//these includes allow us to use many standard library features like strings and vectors
#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cctype>

//including these files allows us to use the classes defined in them
#include "OptionOne.h"
#include "OptionTwo.h"
#include "OptionThree.h"

//allows usage of simpler naming structure
using namespace std;

// Custom exception class for invalid input
class InvalidInput : public std::runtime_error {
public:
	InvalidInput(const std::string& message)
		: std::runtime_error(message) {
	}
};

//converts a string to uppercase
string To_Upper(const string& str) {
	std::string upper_str = str;
	for (char& c : upper_str) {
		c = toupper(c);
	}
	return upper_str;
}

// A function that prevents invalid input from being processed
int processValue(int value) {
	if (value < 0) {
		throw InvalidInput("Value cannot be negative: " + std::to_string(value));
	}
	if (value > 4) {
		throw InvalidInput("Value is too high: " + std::to_string(value));
	}
	std::cout << "You entered: " << value << std::endl;
	return value;
}
// Main function that runs the program
int main() {
	
	// Initialize variables
	int entry = 0;
	string item = "";
	vector<string> AllItems = {}; 

	// Opens the file and reads items into the vector
	ifstream file("Grocery_list.txt");
	if (!file.is_open()) {
		throw std::runtime_error("Could not open file");
	}

	// Reads each line from the file and converts it to uppercase
	std::string line;
	while (std::getline(file, line)) {
		if (!line.empty()) {
			AllItems.push_back(To_Upper(line));
		}
	}

	// Closes the file after reading it
	file.close();

	//while loop to keep the program running until the user chooses to exit
	while (entry != 4) {

		// Display the menu options
		cout << "Options: \n\n";
		cout << "1 : See how many of a specific item was purchased.\n";
		cout << "2 : See all items purchased today.\n";
		cout << "3 : See a chart of items purchased today.\n";
		cout << "4 : Exit Program\n\n";
		cout << "Enter input : "; 

		// asks the user for input
		cin >> entry;

		// Checks if the input is valid
		if (cin.fail()) {
			cerr << "Invalid input: Please enter a whole number." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		
		// Checks if the input is within the valid range
		try {

			// Processes the input value, and may throw an InvalidInput exception
			processValue(entry);

			// A switch statement to handle different menu options
			switch (entry) {

				// Each case is a menu option, case 1 is for searching for a single item
			case 1: {
				cout << "Please enter the item you would like to search for: \n";
				cin >> item;
				OptionOne option(item, AllItems);

				//try block to handle potential exceptions
				try {

					//executes the countItems function to count the number of items
					int count = option.countItems(To_Upper(item));
					cout << "There were " << count << " " << item << " purchased today.\n";

					// Opens the a file in to write the item and its count
					ofstream outputFile("Frequency.dat", std::ios::app);

					// Check if the file was opened successfully
					if (!outputFile) {
						throw std::runtime_error("Could not open Frequency.dat for writing.");
					}

					// Write the item and its count to the file
					else {
						outputFile << item << ": " << count << "\n"; 
					}
					outputFile.close(); // Close the file after writing
				}

				// Catch block to handle runtime errors
				catch (const std::runtime_error& e) {
					std::cerr << "Error: " << e.what() << std::endl;
				}
				cin.clear();
				break;
			}

				  // Case 2: Display all items and their counts
			case 2:

				//try block to handle potential exceptions
				try {

					// Creates an OptionTwo object and calls its methods to display all items and their counts
					OptionTwo option(AllItems);
					option.displayCountPerItem(AllItems);
				}

				// Catch block to handle runtime errors
				catch (const std::runtime_error& e) {
					std::cerr << "Error: " << e.what() << std::endl;
				}
				break;

				// Case 3: Display a chart
			case 3:

				//try block to handle potential exceptions
				try {

					// Creates an OptionThree object and calls its method to display the chart
					OptionThree option(AllItems);
					option.displayChart();
				}

				// Catch block to handle runtime errors
				catch (const std::runtime_error& e) {
					std::cerr << "Error: " << e.what() << std::endl;
				}
				break;

				// Case 4: Exit the program
			case 4:
				cout << "Goodbye! \n";
				return 0;
				break;
			}
		}

		// Catch block to handle custom exceptions
		catch (const InvalidInput& e) { // Catch your specific custom exception
			std::cerr << "Caught InvalidInput: " << e.what() << std::endl;
			// You might want to reset 'entry' or take other actions here
			// to ensure the loop can continue or terminate gracefully.
			// For example, if you want to exit on invalid input:
			// entry = -1;
		}

		// Catch block to handle other standard exceptions
		catch (const std::exception& e) { // Catch any other standard exceptions
			std::cerr << "Caught a standard exception: " << e.what() << std::endl;
		}

		// Catch block to handle any other unknown exceptions, reccomended to me by a friend
		catch (...) {
			std::cerr << "Caught an unknown exception!" << std::endl;
		}
	}

	// Final message to indicate the program has finished
	std::cout << "\nProgram finished." << std::endl;
	return 0;
}