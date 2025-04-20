#include "utils.h"
#include <iostream>
#include <ostream>

void print_header(const std::string &header)
{
    std::string line(header.length(), '-');
    std::cout << "\n\n" << line << std::endl;
    std::cout << header << std::endl;
    std::cout << line << std::endl;
}


