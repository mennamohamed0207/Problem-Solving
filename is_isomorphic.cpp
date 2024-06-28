/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

class Solution {
public:
    bool is_number(const std::string& s) {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it))
            ++it;
        return !s.empty() && it == s.end();
    }
    bool isIsomorphic(string s, string t) {
        if(!is_number(s))
        {vector<char> map(26, '0');
        if (s.length() != t.length())
            return false;
        for (int i = 0; i < s.length(); i++) {

            if (map[s[i] - 97] == '0')
                map[s[i] - 97] = t[i];
            else if (map[s[i] - 97] != t[i])
                return false;
        }
        vector<char> map2(26, '0');

        for (int i = 0; i < s.length(); i++) {

            if (map2[t[i] - 97] == '0')
                map2[t[i] - 97] = s[i];
            else if (map2[t[i] - 97] != s[i])
                return false;
        }
        return true;
        }else
        {// for numbers
        vector<char> map_num(10, 'a');

        for (int i = 0; i < s.length(); i++) {

            if (map_num[s[i] - 48] == 'a')
                map_num[s[i] - 48] = t[i];
            else if (map_num[s[i] - 48] != t[i])
                return false;
        }
        vector<char> map_num2(10, 'a');

        for (int i = 0; i < s.length(); i++) {

            if (map_num2[t[i] - 48] == 'a')
                map_num2[t[i] - 48] = s[i];
            else if (map_num2[t[i] - 48] != s[i])
                return false;
        }

        return true;}
    }
};
//Second Generic Solution
class Solution {
public:
    bool is_number(const std::string& s) {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it))
            ++it;
        return !s.empty() && it == s.end();
    }
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        std::unordered_map<char, char> map_s_to_t;
        std::unordered_map<char, char> map_t_to_s;

        for (int i = 0; i < s.length(); ++i) {
            char char_s = s[i];
            char char_t = t[i];

            // Check mapping from s to t
            if (map_s_to_t.find(char_s) == map_s_to_t.end()) {
                map_s_to_t[char_s] = char_t;
            } else {
                if (map_s_to_t[char_s] != char_t)
                    return false;
            }

            // Check mapping from t to s
            if (map_t_to_s.find(char_t) == map_t_to_s.end()) {
                map_t_to_s[char_t] = char_s;
            } else {
                if (map_t_to_s[char_t] != char_s)
                    return false;
            }
        }

        return true;
    }
    
};