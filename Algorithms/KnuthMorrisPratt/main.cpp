#include <iostream>
#include <string>
#include <vector>

std::vector<int> generateLPS(std::string& s, std::string& pattern) {
    int size = (int)pattern.size();
    std::vector<int> LPS(size, 0);
    int length = 0;
    int i = 1;
    while(i < size) {
        if(pattern[length] == s[i]) {
            length++;
            LPS[i] = length;
            i++;
        } else {
            if(length != 0) {
                length = LPS[length - 1];
            } else {
                LPS[i] = 0;
                i++;
            }
        }
    }
    return LPS;
}

// Knuth Morris Pratt pattern matching algorithm
std::vector<int> KMP(std::string& s, std::string& pattern, std::vector<int>& LPS) {
    int M = pattern.size();
    int N = s.size();
    int i = 0, j = 0;
    std::vector<int> result;
    while(i < N) {
        if(s[i] == pattern[j]) {
            i++;
            j++;
        }

        if(j == M) {
            result.push_back(i - j);
            j = LPS[j - 1];
        } else if(pattern[j] != s[i]) {
            if(j != 0) {
                j = LPS[j - 1];
            } else i++;
        }
    }

    return result;
};

int main() {
    std::string s = "geekxgeek";
    std::string pattern = "geek";
    std::vector<int> LPS = generateLPS(s, pattern);
    std::vector<int> result = KMP(s, pattern, LPS);

    for(int i : result) std::cout << i << std::endl;    
    return 0;
}