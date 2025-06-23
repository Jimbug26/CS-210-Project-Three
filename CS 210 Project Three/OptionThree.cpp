
#include "OptionThree.h"
#include <iostream>
#include <fstream>	
#include <string>
#include <vector>
#include <stdexcept> // Required for std::exception and its derived classes
#include <iomanip>    // For std::setw, std::setfill, etc. if needed
#include <limits>    // For std::numeric_limits
#include <cctype>
#include <map>       // For std::map to count items




OptionThree::OptionThree(const std::vector<std::string>& AllItems) : _VecAllItems(AllItems) {
}
void OptionThree::displayChart() const {
	std::cout << "Chart of available stock:\n";
	std::map<std::string, int> itemCount;

	// Count occurrences of each item
	for (const auto& item : _VecAllItems) {
		itemCount[item]++;
	}

	// Display the chart
	for (const auto& pair : itemCount) {
		std::cout << std::setw(20) << std::left << pair.first << ": " << std::string(pair.second, '*') << " (" << pair.second << ")\n";
	}
}