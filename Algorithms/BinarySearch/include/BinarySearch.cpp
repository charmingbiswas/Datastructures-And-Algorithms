#include <iostream>
#include <vector>
#include "BinarySearch.hpp"

int binarySearch(std::vector<int>& vec, int numberToFind) {
    int n = (int)vec.size();
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        int mid = low + ((high - low) / 2);

        if(vec[mid] == numberToFind) return mid;
        else if(vec[mid] < numberToFind) {
            low = mid + 1;
        } else if(vec[mid] > numberToFind) {
            high = mid - 1;
        }
    }
    return -1;
}
