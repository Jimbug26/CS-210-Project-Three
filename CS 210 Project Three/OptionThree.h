#pragma once
#ifndef OPTIONTHREE_H
#define OPTIONTHREE_H
#include <iostream>	
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept> // Required for std::exception and its derived classes
#include <iomanip>    // For std::setw, std::setfill, etc. if needed
#include <limits>    // For std::numeric_limits
#include <cctype>
#include <map>       // For std::map to count items
#include "OptionTwo.h" // Always include your own header file first
class OptionThree {
private:
	std::vector<std::string> _VecAllItems;
public:
	OptionThree(const std::vector<std::string>& AllItems);
	void displayChart() const;
	
};
#endif // OPTIONTHREE_H
