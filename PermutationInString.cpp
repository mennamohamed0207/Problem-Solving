/*Given two strings s1 and s2, return true if s2 contains a
permutation
 of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.



Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false


Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.*/
// 71 testcases out of 181
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> s1_freq;
        unordered_map<char, int> s2_freq;
        for (int i = 0; i < s1.length(); i++)
        {
            s1_freq[s1[i]]++;
        }
        for (int i = 0; i < s2.length(); i++)
        {
            s2_freq[s2[i]]++;
        }
        for (int i = 0; i < s1.length(); i++)
        {
            if (s2_freq[s1[i]] != s1_freq[s1[i]])
            {
                return false;
            }
        }
        for (int i = 0; i < s2.length() - s1.length(); i++)
        {
            s2_freq[s2[i]]--;
            s2_freq[s2[i + s1.length()]]++;
            if (s1_freq == s2_freq)
            {
                return true;
            }
        }
        return true;
    }
};