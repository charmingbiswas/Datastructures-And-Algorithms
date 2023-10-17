#include <iostream>
#include <vector>
#include "BinarySearch.hpp"

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Does number 3 exist in vector?" << std::endl;
    std::cout << binarySearch(v, 3) << std::endl;
    return 0;
}