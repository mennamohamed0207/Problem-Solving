/*
Given an array of strings strs, group the 
anagrams
 together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters
*/

//Accepted in Neetcode
//Time limit in leetcode
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++) {
            vector<string> ele;
            if(strs[i]!="0")
            ele.push_back(strs[i]);

            for (int j = 0; j < strs.size(); j++) {
                if (i != j && strs[i] != "0" && strs[j] != "0" &&
                    isAnagram(strs[i], strs[j])) {
                    ele.push_back(strs[j]);
                    strs[j] = "0";
                }
            }
            strs[i] = "0";
            if(ele.size()>0)
            result.push_back(ele);
        }
        return result;
    }

private:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> map;
        unordered_map<char, int> map2;
        for (int i = 0; i < s.length(); i++) {
            map[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++) {
            map2[t[i]]++;
        }
        for (int i = 0; i < t.length(); i++) {
            if (map[s[i]] != map2[s[i]])
                return false;
        }

        return true;
    }
};
//Accepted in leetcode
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>map;
        for(auto x:strs)
        {
            string word=x;
            sort(word.begin(),word.end());
            map[word].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x:map)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};