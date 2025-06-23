
//prevents multiple inclusions of this header file
#pragma once

// if the header file is not already defined, define it
#ifndef OPTIONONE_H
#define OPTIONONE_H

//include the necessary libraries
#include <string>
#include <vector>

//this is the class declaration for OptionOne
class OptionOne {
private:

	//these variables hold the produce item to be searched for and a vector of all items and they are used in the optionone class
    std::string _ProduceItem;
	std::vector<std::string> _VecAllItems;
public:

	//these are the constructors for the OptionOne class
    OptionOne(const std::string& frequency, const std::vector<std::string>& AllItems);
    int countItems(std:: string _ProduceItem);
};

// End of the header
#endif