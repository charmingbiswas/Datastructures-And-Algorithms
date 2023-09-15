#include <vector>
#include <iostream>
#include "PartitionAlgo.hpp"

int partitionAlgo(std::vector<int> &v, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = v[low];

    while(i < j) {
        while(v[i] <= pivot)
            i++;
        while(v[j] > pivot)
            j--;
        
        if(i < j)
            std::swap(v[i], v[j]);
    }

    std::swap(v[j], v[low]);

    return j;
    return 0;
}
