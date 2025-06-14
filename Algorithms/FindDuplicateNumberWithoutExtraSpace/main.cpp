#include <iostream>
#include <vector>

int findDuplicate(std::vector<int>& vec) {
    int slow = vec[0];
    int fast = vec[0];

    // two pointers, one fast, one slow
    do {
        slow = vec[slow];
        fast = vec[vec[fast]];
    } while(slow != fast);

    // when both pointers meet, reset slow to o index and again start the processs
    slow = vec[0];
    while(slow !=  fast) {
        slow = vec[slow];
        fast = vec[fast];
    }

    return slow;
}

int main() {
    std::vector<int> vec{5, 1, 6, 2, 4, 6};
    std::cout << findDuplicate(vec) << std::endl;
    return 0;
}
