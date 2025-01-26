class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return \\;  // Handle empty input

        string prefix = strs[0];  // Assume the first string is the prefix

        for (int i = 1; i < strs.size(); i++) {
            // Compare the current prefix with each string in the vector
            while (strs[i].find(prefix) != 0) {
                // Shorten the prefix until it matches the current string
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return \\;  // No common prefix
            }
        }

        return prefix;
    }
};
