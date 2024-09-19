/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/
//Beats 100%
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stackx;

        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stackx.push(s[i]);
            }
            else
            {
                if (stackx.empty() ||
                    (s[i] == ')' && stackx.top() != '(') ||
                    (s[i] == ']' && stackx.top() != '[') ||
                    (s[i] == '}' && stackx.top() != '{'))
                    return false;
                stackx.pop();
            }
        }
        return stackx.empty();
    }
};