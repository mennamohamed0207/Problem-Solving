class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> map;
        for (char c : s) {
            map[c]++;
        }
        int commonFreq = map[s[0]];
        for (auto pair : map) {
            if (pair.second != commonFreq)
                return false;
        }
        return true;
    }
};