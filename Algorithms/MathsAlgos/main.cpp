#include <vector>
#include <iostream>

// operator overloading for printing vectors
std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    for(int i : vec) {
        os << i << " ";
    }
    os << std::endl;
    return os;
}


int greatestProperDivisor(int num) {
    int answer = 1;
    for(int i = 2; i <= num; i++) {
        if(num % i == 0) {
            if(i < num) answer = i;
        }
    }
    return answer;
}

bool isPrime(int number) {
    for(int i = 2; i < std::sqrt(number); i++) {
        if(number % i == 0) return false;
    }

    return true;
}

// prints all the factors of a number
void calculateFactors(int number) {
    std::cout << "Factors of number " << number << " are as follows" << std::endl;
    for(int i = 1; i <= number; i++) {
        if(number % i == 0) std::cout << i << std::endl;
    }
    std::cout << std::endl;
}

void calculatePrimeFactors(int number) {
    std::cout << "Prime factors of number " << number << " are as follows " << std::endl;
    std::vector<int> answer;
    int n = number;
    for(int i = 2; i <= std::sqrt(n); i++) {
        if(n % i == 0) {
            answer.push_back(i);
            while(n % i == 0) {
                n = n / i;
            }
        }
    }
    if(n != 1) answer.push_back(n); // EDGE CASE.
    // basically try to find prime factors for 16, last remaining number will be 1 and we don't add 1 in prime factorization
    // also why are we adding 'n' in the final answer?
    // consider this case, if n = 37. Since 37 itself is a prime number, it will never be divisible by any number
    // also we are iterating from 2 to sqrt(37) which is approx 8....something.
    // so if we don't add number back, in case of prime numbers we will get wrong answer.
    std::cout << answer << std::endl;
}

// greatest common divisor
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int gcdOfArray(std::vector<int>& vec) {
    int currentGCD = vec[0];
    for(int i = 1; i < (int)vec.size(); i++) {
        currentGCD = gcd(currentGCD, vec[i]);
    }
    return currentGCD;
}

int lcmOfArray(std::vector<int>& vec) {
    // calculate LCM
    int LCM = vec[0];
    for(int i = 1; i < (int)vec.size(); i++) {
        LCM = (LCM * vec[i]) / std::__algo_gcd(LCM, vec[i]);
    }
    return LCM;
}

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    return 0;
}