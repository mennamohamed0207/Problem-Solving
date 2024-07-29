/*
Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.

An English letter b is greater than another letter a if b appears after a in the English alphabet.

 

Example 1:

Input: s = "lEeTcOdE"
Output: "E"
Explanation:
The letter 'E' is the only letter to appear in both lower and upper case.
Example 2:

Input: s = "arRAzFif"
Output: "R"
Explanation:
The letter 'R' is the greatest letter to appear in both lower and upper case.
Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
Example 3:

Input: s = "AbCdEfGhIjK"
Output: ""
Explanation:
There is no letter that appears in both lower and upper case.
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase and uppercase English letters.
*/

// Beats 5%
class Solution {
public:
    string greatestLetter(string s) {
        vector<char> Captials;
        for (int i = 0; i < s.length(); i++) {
            if (isupper(s[i])) {
                Captials.push_back(s[i]);
            }
        }
        sort(Captials.begin(), Captials.end());
        string result = "";
        for (int i = Captials.size() - 1; i >= 0; i--) {
            cout << Captials[i] << " " << islower(s[i]) << " " << s[i] << " "
                 << endl;
            for (int j = 0; j < s.length(); j++) {
                if (islower(s[j]) == 512 && Captials[i] == toupper(s[j])) {
                    result += Captials[i];
                    break;
                }
            }
            if (result != "")
                break;
        }
        return result;
    }
};