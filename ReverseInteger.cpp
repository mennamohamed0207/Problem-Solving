/*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1*/

//Beats 100%
class Solution {
public:
    int reverse(int x) {
        vector<long long> numbers;
        if (x < 0) {
           while (x < 0) {
            long long digit = x % 10;
            numbers.push_back(digit);
            x = x / 10;
        }
        }
        while (x > 0) {
            long long digit = x % 10;
            numbers.push_back(digit);
            x = x / 10;
        }
        long long y = 0;
        std::reverse(numbers.begin(), numbers.end());
        for (int i = 0; i < numbers.size(); i++) {
            // cout<<numbers[i]<<" ";
            y += numbers[i] * pow(10, i);
            if(i==numbers.size()-1)
            cout<<endl<<y;
           
        }
        if(y>(pow(2,31)-1)||y<-1*pow(2,31))
        return 0;
        return (y);
    }
};