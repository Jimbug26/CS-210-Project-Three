#pragma once
#ifndef OPTIONONE_H
#define OPTIONONE_H

#include <iostream>
#include <stdexcept> // Required for std::exception and its derived classes
#include <string>    // For std::string
#include <limits>    // For std::numeric_limits+
#include <fstream> 
#include <iomanip> 

class OptionOne {
    





private:
    std::string _ProduceItem;
	std::vector<std::string> _VecAllItems;
public:
    OptionOne(const std::string& frequency, const std::vector<std::string>& AllItems);
    int countItems(std:: string _ProduceItem);

    
    
};
#endif