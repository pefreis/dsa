#include <iostream>
#include <sstream>
#include <vector>

template <typename T>
void readVec(std::vector<T> &out)
{
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    T val;
    while (iss >> val)
        out.push_back(val);
}

template void readVec(std::vector<int> &);