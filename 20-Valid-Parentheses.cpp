class Solution {
public:
    bool isValid(string s) {
        stack<char> St;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                St.push(s[i]);
            else {
                if (St.empty() || (s[i] != ')' && St.top() == '(') ||
                    (s[i] != '}' && St.top() == '{') ||
                    (St.top() == '[' && s[i] != ']')) {
                    return false;
                }
                St.pop();
            }
        }
        return St.empty();
    }
};