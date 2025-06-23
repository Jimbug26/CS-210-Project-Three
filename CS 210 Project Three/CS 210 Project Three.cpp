#include <iostream>
#include <stdexcept> // Required for std::exception and its derived classes
#include <string>    // For std::string
#include <limits>    // For std::numeric_limits+
#include <fstream> 
#include <iomanip> 
#include <vector>
#include <cctype> // For toupper function


#include "OptionOne.h"
#include "OptionTwo.h"
#include "OptionThree.h"





using namespace std;

// Custom exception class for invalid input
class InvalidInput : public std::runtime_error {
public:
	InvalidInput(const std::string& message)
		: std::runtime_error(message) {
	}
};

// A utility function to convert a string to uppercase
string To_Upper(const string& str) {
	std::string upper_str = str;
	for (char& c : upper_str) {
		c = toupper(c);
	}
	return upper_str;
}

// A function that might throw our custom exception
int processValue(int value) {
	if (value < 0) {
		throw InvalidInput("Value cannot be negative: " + std::to_string(value));
		
	}
	if (value > 4) {
		throw InvalidInput("Value is too high: " + std::to_string(value));
		
	}
	std::cout << "Processing value: " << value << std::endl;
	return value;
}

int main() {
	
	int entry = 0;
	
	string item = "";

	vector<string> AllItems = {}; 

	ifstream file("Grocery_list.txt");
	if (!file.is_open()) {
		throw std::runtime_error("Could not open file");
	}

	std::string line;
	while (std::getline(file, line)) {
		if (!line.empty()) {

			AllItems.push_back(To_Upper(line));
		}
	}
	file.close();

	while (entry != 4) {
		cout << "Options: \n\n";
		cout << "1 : See stock for a single item.\n";
		cout << "2 : See all Stock.\n";
		cout << "3 : See a chart of available stock.\n";
		cout << "4 : Exit Program\n\n";
		cout << "Enter input : "; 
		cin >> entry;



		
		if (cin.fail()) {
			cerr << "Invalid input: Please enter a whole number." << endl;
			cin.clear(); // Clear the error flags
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue; // Skip the rest of the loop and ask for input again
		}
		

		// Now, try to process the integer input, which might throw our custom exception
		try {
			processValue(entry);
			switch (entry) {
			case 1: {
				cout << "Please enter the item you would like to search for: \n";
				cin >> item;
				OptionOne option(item, AllItems);
				try {
					int count = option.countItems(To_Upper(item));
					cout << "There are " << count << " items in stock for " << item << ".\n";
				}
				catch (const std::runtime_error& e) {
					std::cerr << "Error: " << e.what() << std::endl;
				}
				cin.clear();
				break;
			}
			case 2:
				cout << "this is case two \n";
				try {
					OptionTwo option(AllItems);
					option.displayAllItems(AllItems);
					option.displayCountPerItem();
				}
				catch (const std::runtime_error& e) {
					std::cerr << "Error: " << e.what() << std::endl;
				}
				
				break;
			case 3:
				cout << "this is case three \n";

				try {
					OptionThree option(AllItems);
					option.displayChart();
				}
				catch (const std::runtime_error& e) {
					std::cerr << "Error: " << e.what() << std::endl;
				}
				break;
			case 4:
				cout << "Goodbye! \n";
				return 0;
				break;
			}
			// Only processValue can throw the InvalidInput exception,
			// so this smaller try block is sufficient if that's all you need to catch.
			// If other things in the loop could throw, extend the try block.

		}
		catch (const InvalidInput& e) { // Catch your specific custom exception
			std::cerr << "Caught InvalidInput: " << e.what() << std::endl;
			// You might want to reset 'entry' or take other actions here
			// to ensure the loop can continue or terminate gracefully.
			// For example, if you want to exit on invalid input:
			// entry = -1;
		}
		catch (const std::exception& e) { // Catch any other standard exceptions
			std::cerr << "Caught a standard exception: " << e.what() << std::endl;
		}
		catch (...) { // Catch any other unknown exceptions (less specific, use sparingly)
			std::cerr << "Caught an unknown exception!" << std::endl;
		}
	}

	std::cout << "\nProgram finished." << std::endl;

	return 0;
}