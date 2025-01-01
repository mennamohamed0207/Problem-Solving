class Solution {
public:
    int maxScore(string s) {
        int oneNum = 0;
        int zeroNum = 0;
        vector<int> scores(s.length());
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1')
                oneNum++;
        }

        for (int i = 0; i < s.length()-1; i++) {
            if (s[i] == '0') {
                zeroNum++;
            } else if (s[i] == '1') {
                oneNum--;
            }
                scores[i] = zeroNum + oneNum;
        }
        int max = *std::max_element(scores.begin(), scores.end());
        return max;
    }
};