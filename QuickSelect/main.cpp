#include <iostream>
#include <vector>
#include "PartitionAlgo.hpp"

/**
 * Ignore these operator overloads, nothing to do with the algorithm, just making it easy to print certain data structures
*/
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



// ============================================================= //


/**
 * This QuickSelect algorightm is used to solve problems where "top K element" type questions need to be solved
 * Basically when you want to select multiple elements on the basis of some criteria, like most frequent elements in an array
*/
// Function prototype for QuickSelect algorithm
void QuickSelect(std::unordered_map<int, int> &map, std::vector<int> &vec, int low, int high, int k);

// Function to return top k frequent elements in an array using quick select algorithm
std::vector<int> topKFrequentElements(std::vector<int> &vec, int k);



int main() {
    // Create a random vector
    std::vector<int> v = {5, 3, 2, 10, 9, 11, 7, 5, 5, 7, 8, 8, 8, 8, 8};

    // For K = 2, we need to select top '2' frequent elements
    int k = 2;
    std::cout << topKFrequentElements(v, k) << std::endl;
    return 0;
}

void QuickSelect(std::unordered_map<int, int> &map, std::vector<int> &vec, int low, int high, int k) {
        if(low == high) return;

        int position = partitionAlgo(map, vec, low, high);
        if(position == k) return;
        else if(position < k) QuickSelect(map, vec, position + 1, high, k);
        else if(position > k) QuickSelect(map, vec, low, position - 1, k);
    }

std::vector<int> topKFrequentElements(std::vector<int>& vec, int k)
{
    std::vector<int> unique;
    std::unordered_map<int, int> frequencyMap;
    for(int i : vec)
        frequencyMap[i] += 1;

    for(auto i : frequencyMap)
        unique.push_back(i.first);

    int n = unique.size();
    QuickSelect(frequencyMap, unique, 0, n - 1, n - k);
    std::vector<int> result;
    for(int i = k; i > 0; i--)
        result.push_back(unique[n - i]);

    return result;
}
