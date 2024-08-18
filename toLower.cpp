/*
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

 

Example 1:

Input: s = "Hello"
Output: "hello"
Example 2:

Input: s = "here"
Output: "here"
Example 3:

Input: s = "LOVELY"
Output: "lovely"
 

Constraints:

1 <= s.length <= 100
s consists of printable ASCII characters.
*/
//Beats 100%
#include<climits>
class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.length();i++)
        {
            if(isupper(s[i]))
            s[i]+=32;
        }
        return s;
    }
};