#include <iostream>
#include <string>
#include <vector>

void generateLPS(std::string pattern, std::vector<int>& LPS) {
    int size = (int)pattern.size();
    int i = 1;
    LPS[0] = 0;
    int length = 0;

    while(i < size) {
        if(pattern[i] == pattern[length]) {
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
}

std::vector<int> KMP(std::string str, std::string pattern) {
    int M = (int)str.size();
    int N = (int)pattern.size();
    int i = 0, j = 0;
    std::vector<int> answer;
    std::vector<int> LPS(N, 0);
    generateLPS(pattern, LPS);

    while(i < M) {
        if(str[i] == pattern[j]) {
            i++;
            j++;
        }

        if(j == N) {
            answer.push_back(i - j); // for zero based index. For 1 based index, just +1 at the end
            j = LPS[j - 1];
        } else if(str[i] != pattern[j]) {
            if(j != 0) {
                j = LPS[j - 1];
            } else i++;
        }
    }

    return answer;
}

int main() {
    std::string s = "aabaaabaaac";  
    // std::string s = "mississippi";
    // std::string pattern = "issipi";
    std::string pattern = "aabaaac";
    std::vector<int> result = KMP(s, pattern);
    for(auto i : result) {
        std::cout << i << std::endl;
    }
    if(result.size() > 0) {
        std::cout << result[0];
    } else std::cout << -1;
    // for(int i : result) std::cout << i << std::endl;    
    return 0;
}