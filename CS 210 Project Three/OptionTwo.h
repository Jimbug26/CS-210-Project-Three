
//prevent multiple inclusions of the header file
#pragma once

// if the header file is not already defined, define it
#ifndef OPTIONTWO_H
#define OPTIONTWO_H

//these includes allow us to use many standard library features like strings and vectors
#include <string>
#include <vector>

//this is the class declaration for OptionTwo
class OptionTwo {
private:

	//this variable holds a vector of all items
	std::vector<std::string> _VecAllItems;
public:

	//this is the constructor for the OptionTwo class
	OptionTwo(const std::vector<std::string>& AllItems);
	
	//a function that displays each item and its count
	void displayCountPerItem(std::vector<std::string>& _VecAllItems) const;
	
};

// End of the header
#endif