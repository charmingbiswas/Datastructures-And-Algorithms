#include <iostream>
#include <vector>

// overload '<<' operator to directly print vectors
std::ostream &operator<<(std::ostream &os, const std::vector<int> &v)
{
    for(int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << " ";
    }

    return os;
}

void merge(std::vector<int>& vec, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int size = (int)vec.size();
    std::vector<int> tempVec(size, 0);

    while(i <= mid && j <= high)
    {
        if(vec[i] <= vec[j])
            tempVec[k++] = vec[i++];
        else
            tempVec[k++] = vec[j++];
    }

    while(i <= mid)
        tempVec[k++] = vec[i++];
    
    while(j <= high)
        tempVec[k++] = vec[j++];

    for(int p = low; p <= high; p++)
    {
        vec[p] = tempVec[p];
    }
}

void mergeSort(std::vector<int>& v, int low, int high) {
    if(low < high) 
    {
        int mid = low + (high - low) / 2;
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        merge(v, low, mid, high);
    }
}



int main() {
    // Create a random vector
    std::vector<int> v = {5, 3, 2, 10, 9, 11, 11, 11, 5};
    std::cout << "Vector before merge sort\n";
    std::cout << v << std::endl;
    mergeSort(v, 0, (int)v.size() - 1);
    std::cout << "Vector after merge sort\n";
    std::cout << v << std::endl;
    return 0;
}



