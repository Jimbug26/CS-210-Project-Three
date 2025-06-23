#pragma once
#ifndef OPTIONTWO_H
#define OPTIONTWO_H
#include <iostream>
#include <fstream>
#include <string>
	
#include <vector>
#include <stdexcept> // Required for std::exception and its derived classes
#include <iomanip>    // For std::setw, std::setfill, etc. if needed
#include <limits>    // For std::numeric_limits
#include <cctype>


class OptionTwo {
private:
	std::vector<std::string> _VecAllItems;
public:
	OptionTwo(const std::vector<std::string>& AllItems);
	
	void displayAllItems(std::vector<std::string>& _VecAllItems) const;
	void displayCountPerItem() const;
	
};
#endif // OPTIONTWO_H