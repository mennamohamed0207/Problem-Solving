/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.

 

Example 1:

Input: n = 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
Example 3:

Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.
 

Constraints:

-231 <= n <= 231 - 1
*/
//Beat 24.25%
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
   vector<int> primeFactors(int n) {
    vector<int> factors;

    
    if (n < 0) {
        factors.push_back(-1);
        n = -n; 
    }

    
    while (n % 2 == 0) {
        factors.push_back(2);
        n = n / 2;
    }

    
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }

    
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}
    bool isUgly(int n) {
        if(n==pow(2,31)*-1) return false;
        if(n==0) return false;
       
        vector<int> factors = primeFactors(n);
        for (int i = 0; i < factors.size(); i++) {
            cout << factors[i] << " ";
            if (factors[i] != 2 && factors[i] != 3 && factors[i] != 5)
                return false;
        }
        return true;
    }
};