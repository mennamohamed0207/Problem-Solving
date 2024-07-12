/*
You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.
*/
//First Solution O(n^2) 53/63 test cases passed 
//time limit exceeded
class Solution {
public:
    bool findSubstring(string sub,string& s)
    {
        int j=0;
        for(int i=0;i<s.length();i++)
        {
            j=i+1;
            if(s[i]==sub[0])
            {
                while(s[j]=='0')
                {
                    j++;
                }
            }
            if(i<s.length()&&s[i]==sub[0]&&s[j]==sub[1])
           { s[i]='0';
            s[j]='0';
            return true;}
        }
        return false;
    }
    int maximumGain(string s, int x, int y) {
        int result=0;
        if(x>y)
        {
            while (findSubstring("ab",s))
            {

                result+=x;
            }
            cout<<s;
            while (findSubstring("ba",s))
            {
                result+=y;
            }
        }else {
             while (findSubstring("ba",s))
            {
                result+=y;
            }
             while (findSubstring("ab",s))
            {
                result+=x;
            }
        }
        return result;
    }
};
//Second Solution that passed using stack
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int result = 0;

        if (x > y) {
            result += calculatePoints(s, 'a', 'b', x);
            result += calculatePoints(s, 'b', 'a', y);
        } else {
            result += calculatePoints(s, 'b', 'a', y);
            result += calculatePoints(s, 'a', 'b', x);
        }

        return result;
    }

private:
    int calculatePoints(string& s, char first, char second, int points) {
        stack<char> st;
        int score = 0;

        for (char c : s) {
            if (!st.empty() && st.top() == first && c == second) {
                st.pop();
                score += points;
            } else {
                st.push(c);
            }
        }

        // Reconstruct the string without the removed pairs
        string temp;
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        s = temp;

        return score;
    }
};
