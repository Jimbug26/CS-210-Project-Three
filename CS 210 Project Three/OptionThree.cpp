//these includes allow us to use many standard library features like strings and vectors
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <map>

//includes the header file for OptionThree class
#include "OptionThree.h"

// Constructor for OptionThree class
OptionThree::OptionThree(const std::vector<std::string>& AllItems) : _VecAllItems(AllItems) {
}

// Function to display a chart of items
void OptionThree::displayChart() const {
	std::cout << "Chart of items purchased today:\n";
	std::map<std::string, int> itemCount;

	// Count occurrences of each item
	for (const auto& item : _VecAllItems) {
		itemCount[item]++;
	}

	// Display the chart
	for (const auto& pair : itemCount) {
		std::cout << std::setw(20) << std::left << pair.first << ": " << std::string(pair.second, '*') << " (" << pair.second << ")\n";

		// Writes to file
		std::ofstream outputFile("Frequency.dat", std::ios::app);
		outputFile << std::setw(20) << std::left << pair.first << ": "
			<< std::string(pair.second, '*') << " (" << pair.second << ")\n";
	}
}