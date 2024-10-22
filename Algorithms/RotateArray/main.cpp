#include <iostream>
#include <string>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    for(int i : vec) {
        os << i << " ";
    }
    os << std::endl;
    return os;
}

// this function can either rotate left or right, by any number of steps

void rotate(std::vector<int>& vec, int rotation, std::string rotateDir) {
    int n = vec.size();
    std::vector<int> rotatedArray(n);
    if(rotateDir == "right") {
        for(int i = 0; i < n; i++) {
            rotatedArray[(i + rotation) % n] = vec[i]; // THIS LOGIC IS AS FOLLOWS
            // 1, 2, 3
            // for k = 1;
            // index 0 -> index 1, meaning = newIndex = i + k = (0 + 1) % n = 1 
            // so for K rotations, it means current index will be shifted to right k times.
            // So current index will be current + k
            // now to make sure it fits the bounds of the array, just take mod of this number with length of the array
        }

        for(int i = 0; i < n; i++) {
            vec[i] = rotatedArray[i];
        }
    } else if(rotateDir == "left") {
        for(int i = 0; i < n; i++) {
            int current = ((i - rotation) + n) % n;
            rotatedArray[current] = vec[i];
        }

        for(int i = 0; i < n; i++) {
            vec[i] = rotatedArray[i];
        }
    }
};

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    rotate(vec, 1, "left");
    std::cout << vec << std::endl;
    return 0;
}