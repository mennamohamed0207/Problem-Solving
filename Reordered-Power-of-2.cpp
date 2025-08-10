#include <cmath>
#include <iostream>
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int power = log2(n);
        return pow(2, power) == n;
    }
    bool reorderedPowerOf2(int n) {
        if (isPowerOfTwo(n))
            return true;
        // separate the digits
        vector<int> digits;
        while (n != 0) {
            int digit = n % 10;
            n = n / 10;
            digits.push_back(digit);
        }
        sort(digits.begin(), digits.end());

        do {
            if (digits[0] == 0)
                continue;
            int canditate = 0;
            for (int i = 0; i < digits.size(); i++) {
                canditate = canditate * 10 + digits[i];
            }
                if (isPowerOfTwo(canditate))
                    return true;
        } while (next_permutation(digits.begin(), digits.end()));

        return false;
    }
};