/*
You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
 

Constraints:

1 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It is guaranteed that all parentheses are balanced.
*/
//First Solution of my own but doesn't work for all test cases
#include <stack>

class Solution {
public:
    bool thereisparentheses(string test) {
        for (int i = 0; i < test.length(); i++) {
            if (test[i] == '(' || test[i] == ')')
                return false;
        }
        return true;
    }
    string reverseParentheses(string s) {
        stack<char> reversed_without_parentheses;
        stack<char> stack_result;
        string result = s;
        string output ="";
        int len=0;
        for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i]))
                len++;
        }
        while (thereisparentheses(result) || result == s) {
            for (int i = 0; i < result.length(); i++) {
                if (result[i] == '(') {
                    int stop=i;
                    i++;
                    int open=0;

                    while (result[i] != ')' &&isalpha(result[i])) {
                        reversed_without_parentheses.push(result[i]);
                        i++;
                        if(result[i]=='(')
                        {
                            open++;
                        }
                    }
                        if(result[i]==')' && open >0)
                        {
                            open--;
                            continue;
                        }
                    while (!reversed_without_parentheses.empty()) {
                        char temp = reversed_without_parentheses.top();
                        reversed_without_parentheses.pop();

                        
                        if(stop<result.length())
                       { result[stop]=temp;
                        stop++;}
                    }
                }
            }
            
            
        }
        string final1="";
        for(int i=0;i<len;i++)
        {
            final1+=result[i];
        }
        return final1;
    }
};
//The accepted one with the help of chatgpt
#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stack;
        string current;

        for (char c : s) {
            if (c == '(') {
                // Push the current string onto the stack and start a new one
                stack.push(current);
                current = "";
            } else if (c == ')') {
                // Reverse the current string and append it to the top of the stack
                reverse(current.begin(), current.end());
                if (!stack.empty()) {
                    current = stack.top() + current;
                    stack.pop();
                }
            } else {
                // Append the character to the current string
                current += c;
            }
        }
        
        return current;
    }
};
