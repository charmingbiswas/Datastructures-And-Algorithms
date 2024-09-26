#include <iostream>
#include <vector>
#include <numeric>

// -------------- BRUTE FORCE -------------------- //
int shipWithinDays(std::vector<int> weights, int days) {
    int minCapacity = *std::max_element(weights.begin(), weights.end());
    
    bool flag = true;

    while(flag) {
        int sum = 0;
        int daysUsed = 1;

        for(int i = 0; i < (int)weights.size(); i++) {
            sum += weights[i];
            if(sum > minCapacity) {
                sum = weights[i];
                daysUsed++;
            }
        }

        if(daysUsed <= days) {
            flag = false;
        }
        minCapacity++;
    }
    return minCapacity;
}

// -------------- OPTIMIZED (MODIFIED BINARY SEARCH) -------------- /

int shipWithinDaysOpt(std::vector<int> weights, int days) {

    int minCapacity = *std::max_element(weights.begin(), weights.end()); // avg
    int maxCapacity = std::accumulate(weights.begin(), weights.end(), 0);

    int low = minCapacity;
    int high = maxCapacity;
    

    while(low <= high) {
        int mid = (low + high) / 2;
        int sum = 0;
        int daysUsed = 1;
        for(int i = 0; i < (int)weights.size(); i++) {
            sum += weights[i];
            if(sum > mid) {
                sum = weights[i];
                daysUsed++;
            }
        }
        if(daysUsed > days) {
            low = mid + 1;
        } else high = mid - 1;
    }
    return low;
}


int main() {
    std::vector<int> v = {1,2,3,1,1}; int days = 4;
    std::cout << shipWithinDays(v, days) << std::endl;
    return 0;
}                                                                         