
//these includes allow us to use many standard library features like strings and vectors
#include <iostream>  
#include <string>   
#include <vector>   

//including the header file for OptionOne class
#include "OptionOne.h"

// Constructor for OptionOne class
OptionOne::OptionOne(const std::string& ProduceItem, const std::vector<std::string>& AllItems) : _ProduceItem(ProduceItem), _VecAllItems(AllItems) {
}

// Function to count the number of items purchased for a specific produce item
int OptionOne::countItems(std::string _ProduceItem) {

	//variable to hold the count of items
	int count = 0;

	// Iterates through the vector and counts occurrences of the item
	for (const auto& item : _VecAllItems) {
		if (item == _ProduceItem) {
			count++;
		}
	}

	// If no items were found, throw an exception
	if (count == 0) {
		std::cout << "No items found for that specific product: " << _ProduceItem << "\n";
	}
	
	return count;
}