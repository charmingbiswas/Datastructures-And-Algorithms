#include <iostream>
#include <vector>
#include "PartitionAlgo.hpp"



/**
 * This QuickSelect algorightm is used to solve problems where "top K element" type questions need to be solved
 * Basically when you want to select multiple elements on the basis of some criteria, like most frequent elements in an array
*/
// Function prototype for QuickSelect algorithm
void QuickSelect(std::unordered_map<int, int> &map, std::vector<int> &vec, int low, int high, int k);




// overload '<<' operator to directly print vectors
std::ostream &operator<<(std::ostream &os, const std::vector<int> &v)
{
    for(int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << std::endl;
    }

    return os;
}

// overload '<<' operator to directly print maps
std::ostream &operator<<(std::ostream &os, const std::unordered_map<int, int> &map)
{
    for(auto i : map)
    {
        os << "Element is " << i.first << " and value is " << i.second << std::endl;
    }

    return os;
}



int main() {
    // Create a random vector
    std::vector<int> v = {5, 3, 2, 10, 9, 11, 7, 5, 5, 7, 8, 8, 8, 8, 8};

    // For K = 2, we need to select top '2' frequent elements
    std::unordered_map<int, int> map;

    // store frequency of every element in a map
    for(auto i : v) {
        map[i] += 1; 
    }

    


    return 0;
}

void QuickSelect(std::unordered_map<int, int> &map, std::vector<int> &vec, int low, int high, int k) {
    if(low < high) {
        int n = vec.size() - 1;
        int pivotElementIndex = partitionAlgo(vec, low, high);

        if(pivotElementIndex < (n - k)) {

        }
        else if(pivotElementIndex >= (n - k)) {

        }
    }
}
