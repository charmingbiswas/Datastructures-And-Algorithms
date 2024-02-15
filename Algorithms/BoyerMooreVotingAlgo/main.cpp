#include <iostream>
#include <vector>


// BOYER MOORE VOTING ALGORIGHT - use to find most recurring element in an array in constant space O(1)
// Most recurring means any element with more than n/2 repetitions where n is the size of the array


int findMajorityElement(std::vector<int>& vec) {
    int current;
    int count = 0;

    for(auto i : vec) {
        if(count == 0) current = i;
        if(current == i) count++;
        else count--;
    }

    return current;
};


int main() {
    std::vector<int> v {3, 2, 3, 3, 3, 3, 3, 2 }; // answer should be 3
    std::cout << findMajorityElement(v) << std::endl;
    return 0;
};