#include <iostream>
#include <vector>
#include <ostream>
std::vector<std::vector<int>> subsetsWithoutDuplicates(std::vector<int>&);
void helper(std::vector<int>&, std::vector<int>&, std::vector<std::vector<int>>&, int);

//overload '<<' operator
std::ostream &operator<<(std::ostream& os, const std::vector<std::vector<int>>& vec) {
    for(auto i : vec) {
        os << "[ ";
        for(int j = 0; j < (int)i.size(); j++) {
            if(j == (int)i.size() - 1) {
                os << i[j];
            } else {
                os << i[j] << ", ";
            }
        }
        os << " ]" << std::endl;
    }

    return os;
}

int main()
{
    std::vector<int> vec {1, 3, 2, 2};
    std::cout << subsetsWithoutDuplicates(vec) << std::endl;
    return 0;
};


std::vector<std::vector<int>> subsetsWithoutDuplicates(std::vector<int>& nums) {
    std::vector<std::vector<int>> answer;
    std::vector<int> temp;
    std::sort(nums.begin(), nums.end());
    helper(nums, temp, answer, 0);
    return answer;
}


void helper(std::vector<int>& nums, std::vector<int>& temp, std::vector<std::vector<int>>& answer, int index) {
    if(index >= (int)nums.size()) {
        answer.push_back(temp);
        return;
    }

    //select
    temp.push_back(nums[index]);
    helper(nums, temp, answer, index+1);
    temp.pop_back();
    
    //dont't select
    while(index + 1 < (int)nums.size() && nums[index] == nums[index + 1]) {
        index++;
    }
    helper(nums, temp, answer, index + 1); 
};
