#include <iostream>
#include <vector>
#include <string>

bool helper(std::string& s, int low, int high, bool canDelete) {
    while(low < high) {
        if(s[low] == s[high]) {
            low++;
            high--;
        } else {
            if(canDelete) {
                return helper(s, low + 1, high, false) || helper(s, low, high - 1, false);
            } else return false;
        }
    }

    return true;
};

bool validPalindrome(std::string s) {
    int low = 0;
    int high = s.size() - 1;
    bool canDelete = true;
    return helper(s, low, high, canDelete);
};



int main()
{
    std::cout << validPalindrome("cbbcc");
    return 0;
};

