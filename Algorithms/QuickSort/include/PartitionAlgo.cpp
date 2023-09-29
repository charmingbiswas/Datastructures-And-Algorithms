#include <vector>
#include <iostream>
#include "PartitionAlgo.hpp"

int partitionAlgo(std::vector<int> &v, int low, int high)
{
    int i = low;    // low pointer
    int j = high;   // high pointer
    int pivot = v[low]; // randomly selected pivot value, can be anything, in this case we are using it as the first element of the array

    while(i < j) {
        // keep incrementing low pointer untill it reaches an element which is greater than pivot
        while(i <= high && v[i] <= pivot)
            i++;

        // keep decrementing high pointer untill it reaches an element which is lesser than pivot
        while(j >= low && v[j] > pivot)
            j--;
        
        // swap values at low pointer and high pointer
        if(i < j)
            std::swap(v[i], v[j]);
    }

    // once low pointer has crossed high pointer, the high pointer index is the value where the pivot value has to be placed
    std::swap(v[j], v[low]);

    //return index pointed to by high pointer, in this case, index of the pivot element
    return j;
}
