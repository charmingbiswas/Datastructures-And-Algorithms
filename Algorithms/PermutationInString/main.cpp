#include <iostream>
#include <string>
#include <unordered_map>

bool areMapsEqual(std::unordered_map<char, int>& m1, std::unordered_map<char, int>& m2) {
    for(auto c : m1) {
        if(m1[c.first] != m2[c.first]) return false;
    }

    return true;
};

bool checkInclusion(std::string s1, std::string s2) {
    std::unordered_map<char, int> m1;
    std::unordered_map<char, int> m2;
    for(char c : s1) {
        m1[c]++;
    }

    int start = 0, end = 0;
    while(end < (int)s2.size()) {
        m2[s2[end]]++;
        int lengthOfWindow = end - start + 1;
        if(lengthOfWindow == (int)s1.size() && areMapsEqual(m1, m2)) {
            return true;
        }

        if(lengthOfWindow < (int)s1.size()) {
            end++;
        } else {
            m2[s2[start]]--;
            start++;
            end++;
        }
    }

    return false;
};

int main()
{
    std::string s1 = "ab";
    std::string s2 = "eidboaoo";
    std::cout << checkInclusion(s1, s2) << std::endl;
    return 0;
};