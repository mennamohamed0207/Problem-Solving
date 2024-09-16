/*Given two strings s and t, return true if t is an 
anagram
 of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?*/
//Beats 45.99

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>map;
        unordered_map<char,int>map2;
        for(int i=0;i<s.length();i++)
        {
            map[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            map2[t[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            if(map[s[i]]!=map2[s[i]])
                return false;
        }

        return true;

    }
};
