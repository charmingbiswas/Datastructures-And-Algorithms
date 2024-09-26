#include <iostream>
#include <vector>
#include <string>
#include <map>

// ------ BRUTE FORCE ---- //
// find all substrings of word1
// save frequency of all chars in word2, compare to frequencies in all substring of word1
// increment count, return it

long long validSubstringCount(std::string word1, std::string word2) {
    int answer = 0;
    std::vector<std::string> allSubstrings;
    std::unordered_map<char, int> freq;
    for(auto i : word2) {
        freq[i]++;
    }

    for(int i = 0; i < (int)word1.size(); i++) {
        for(int j = i; j < (int)word1.size(); j++) {
            std::string sub = word1.substr(i, j - i + 1);
            allSubstrings.push_back(sub);
        }
    }

    for(auto sub : allSubstrings) {
        std::vector<int> count(26, 0);
        for(auto c : sub) {
            count[c - 'a']++;
        }

        int isValid = true;
        for(auto i : freq) {
            if(i.second <= count[i.first - 'a']) continue;
            else isValid = false;
        }

        if(isValid) answer++;
    }

    return answer;
}



// ------- OPTIMIZED ---- //
// use sliding window, keep track of counts again
// basically requency of all chars in s2 should be available in the current window to make it valid.
// 

long long validSubstringCountOpt(std::string s1, std::string s2) {
    long long answer = 0;
    int requiredCount = (int)s2.size(); // total count of characters needed in the window
    std::unordered_map<char, int> freq2; // frequency of all chars in s2, use this to compare the chars in the window
    int i = 0, j = 0; // low and high pointers
    for(auto c : s2) freq2[c]++;

    while(j < (int)s1.size()) {
        char c = s1[j];
        if(freq2[c] > 0) requiredCount--;
        freq2[c]--;

        while(requiredCount == 0) {
            answer++;
            answer += s1.length() - (j + 1); // basically if current window matches the required frequency of char, then ALL windows after end pointer will match
            // once you have exhausted all chars in s2, start incrementing low pointer, and increment the frequencies of chars that you are leaving/ignoring
            char x = s1[i];
            freq2[x]++;

            if(freq2[x] > 0) {
                requiredCount++;
            }
            i++;
        }

        j++;
    }

    return answer;
}
int main() {
    std::cout << validSubstringCountOpt("bcca", "abc") << std::endl;
    return 0;
}