#include <iostream> 
#include <fstream>  
#include <string>   
#include <vector>
#include <stdexcept> // Required for std::exception and its derived classes	
#include <iomanip>    // For std::setw, std::setfill, etc. if needed
#include <limits>    // For std::numeric_limits	
#include <cctype>

#include "OptionOne.h" // Always include your own header file first

OptionOne::OptionOne(const std::string& ProduceItem, const std::vector<std::string>& AllItems) : _ProduceItem(ProduceItem), _VecAllItems(AllItems) {
}

int OptionOne::countItems(std::string _ProduceItem) {
	int count = 0;
	// Iterate through the vector and count occurrences of the frequency
	for (const auto& item : _VecAllItems) {
		if (item == _ProduceItem) {
			count++;
		}
	}
	// If no items were found, throw an exception
	if (count == 0) {
		std::cout << "No items found for the specified product: " << _ProduceItem << "\n";
	}
	
	return count;
}