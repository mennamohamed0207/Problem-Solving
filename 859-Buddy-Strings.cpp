class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int firstIndex = 0;
        int secondIndex = 1;
        if (s.length() != goal.length())
            return false;
        if (s == goal) {
            set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size(); // Swapping same characters
            }
            int diff = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != goal[i]) {
                    diff++;
                if (diff == 1)
                    firstIndex = i;
                else if (diff == 2) {
                    secondIndex = i;
                }
                }
                if(diff>2) return false;
            }
            return diff==2&&s[secondIndex] == goal[firstIndex] &&
                   s[firstIndex] == goal[secondIndex];
        }
    };

