
//prevent multiple inclusions of the header file
#pragma once

// if the header file is not already defined, define it
#ifndef OPTIONTHREE_H
#define OPTIONTHREE_H

//these includes allow us to use many standard library features like strings and vectors
#include <string>
#include <vector>
#include <map>

//includes the header file for OptionThree class
#include "OptionThree.h" 

//this is the class declaration for OptionThree
class OptionThree {
private:

	//this variable holds a vector of all items
	std::vector<std::string> _VecAllItems;
public:

	//this is the constructor for the OptionThree class
	OptionThree(const std::vector<std::string>& AllItems);

	//a function that displays a chart of items
	void displayChart() const;
	
};

// End of the header
#endif
