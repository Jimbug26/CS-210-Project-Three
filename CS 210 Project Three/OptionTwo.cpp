//these includes allow us to use many standard library features like strings and vectors
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <fstream>

//includes the header file for OptionTwo class
#include "OptionTwo.h" // Always include your own header file first

// constructor for OptionTwo class
OptionTwo::OptionTwo(const std::vector<std::string>& AllItems) : _VecAllItems(AllItems) {
}	

// a fumction that displays each item and its count
void OptionTwo::displayCountPerItem(std::vector<std::string>& _VecAllItems) const {
	std::cout << "Count of each item purchased today:\n";

	// Create a map to count occurrences of each item
	std::map<std::string, int> itemCount;

	// Count occurrences of each item in the vector
	for (const auto& item : _VecAllItems) {
		itemCount[item]++;
	}

	//displays and writes to file each item and its count
	for (const auto& pair : itemCount) {
		std::cout << pair.first << ": " << pair.second << "\n";
		std::ofstream outputFile("Frequency.dat", std::ios::app); // Open file in append mode
		outputFile << pair.first << ": " << pair.second << "\n"; // Write to file
		outputFile.close(); // Close the file after writing
	}
	
	
}