#include <iostream>
#include <string>
#include <vector>


int countPrimes(int n) {
    int count = 0;
    std::vector<bool> vec(n + 1, true);
    for(int i = 2; i < n; i++) {
        if(vec[i]) {
            count++;
            for(int j = 2*i; j < n; j = j + i) {
                vec[j] = false;
            }
        }
    }
    return count;     
}

int main()
{
    std::cout << countPrimes(10) << std::endl;
    return 0;
};
