#include <iostream>
#include <vector>

#include "PartitionAlgo.hpp"

int main() {
    std::vector<int> v = {1, 3, 2, 10, 9, 11};
    int index = (int)v.size() - 1;
    std::cout << partitionAlgo(v, 0, index);
    std::cout << "Hello world\n";
    return 0;
}