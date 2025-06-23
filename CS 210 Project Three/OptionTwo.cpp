#include <iostream>
#include <fstream>
#include <string>
#include <vector>	
#include <map>       // For std::map to count items
#include <stdexcept> // Required for std::exception and its derived classes
#include <iomanip>    // For std::setw, std::setfill, etc. if needed
#include <limits>    // For std::numeric_limits	
#include <cctype>	
#include "OptionTwo.h" // Always include your own header file first



OptionTwo::OptionTwo(const std::vector<std::string>& AllItems) : _VecAllItems(AllItems) {
}	

void OptionTwo::displayAllItems(std::vector<std::string>& _VecAllItems) const {
	std::cout << "All items in stock:\n";
	for (const auto& item : _VecAllItems) {
		std::cout << item << "\n";
	}
}
void OptionTwo::displayCountPerItem() const {
	std::cout << "Count of each item in stock:\n";
	std::map<std::string, int> itemCount;
	for (const auto& item : _VecAllItems) {
		itemCount[item]++;
	}
	for (const auto& pair : itemCount) {
		std::cout << pair.first << ": " << pair.second << "\n";
	}
	
	
}