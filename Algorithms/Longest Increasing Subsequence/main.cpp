#include <iostream>
#include <vector>

/**
 * TIME COMPLEXITY - O(NlogN);
 * SPACE COMPLEXITY - O(N);
*/

int lengthOfLongestIncreasingSubsequence(std::vector<int>&); //function prototype

int main() {
    std::vector<int> nums = {10,9,2,5,3,7,101,18};
    //find the longest strictly increasing subsequence, in this case it should be [2, 3, 7, 101]
    // so return 4 as length is 4

    return 0;
}


int lengthOfLongestIncreasingSubsequence(std::vector<int>& nums) {
    std::vector<int> answer;
    for(int i = 0; i < (int)nums.size(); i++) {
        if(answer.empty() || answer[answer.size() - 1] < nums[i]) {
            answer.push_back(nums[i]);
        } else {
            auto it = std::lower_bound(answer.begin(), answer.end(), nums[i]);
            *it = nums[i];
        }
    }

    return (int)answer.size();
}