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

        return true;
    }
};
//Accepted Answer Beats 31%
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        // Frequency map for s1
        unordered_map<char, int> s1_freq;
        for (int i = 0; i < s1.length(); i++) {
            s1_freq[s1[i]]++;
        }
        
        // Sliding window to match the frequency of s1 with substrings of s2
        unordered_map<char, int> s2_freq;
        for (int i = 0; i < s2.length(); i++) {
            s2_freq[s2[i]]++;
            
            // If the window size exceeds s1's length, remove the leftmost element
            if (i >= s1.length()) {
                s2_freq[s2[i - s1.length()]]--;
                if (s2_freq[s2[i - s1.length()]] == 0) {
                    s2_freq.erase(s2[i - s1.length()]);
                }
            }
            
            // Check if the current window's frequency map matches s1's frequency map
            if (s1_freq == s2_freq) {

                
                return true;
            }
        }

        return false;
    }
};

//Another Answer that Beats 94%
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        vector<int> s1_freq(26, 0), s2_freq(26, 0);
        
        // Build frequency map for s1 and the first window of s2
        for(int i = 0; i < s1.length(); i++) {
            s1_freq[s1[i] - 'a']++;
            s2_freq[s2[i] - 'a']++;
        }

        // Now slide the window over s2
        for(int i = s1.length(); i < s2.length(); i++) {
            if(s1_freq == s2_freq) return true;
            
            // Slide the window: remove the char at start and add the char at current
            s2_freq[s2[i] - 'a']++;                // Add new character to the window
            s2_freq[s2[i - s1.length()] - 'a']--;  // Remove the old character from the window
        }

        // Check the last window after the loop ends
        return s1_freq == s2_freq;
    }
};
