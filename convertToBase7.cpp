/*
Given an integer num, return a string of its base 7 representation.

 

Example 1:

Input: num = 100
Output: "202"
Example 2:

Input: num = -7
Output: "-10"
 

Constraints:

-107 <= num <= 107
*/

// Beats 38.90%
class Solution {
public:
    string convertToBase7(int num) {
        string reversed="";
        string result="";
        int number=num;
       if(num==0) return "0";
        while(num!=0)
        {
            int digit=num%7;
            if(digit<0) digit=abs(digit);
            reversed+=to_string(digit);
            num=num/7;
        }
         if(number<0)
        reversed+='-';
        std::reverse(reversed.begin(),reversed.end());
        return reversed;
    }
};