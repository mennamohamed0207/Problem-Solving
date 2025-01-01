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
        bool allOnes = true;
        bool allZeros = true;
        for (int i = 0; i < s.length()-1; i++) {
            if (s[i] == '0') {
                allOnes = false;
                zeroNum++;
            } else if (s[i] == '1') {
                allZeros=false;
                oneNum--;
            }
                scores[i] = zeroNum + oneNum;
        }
        int max = *std::max_element(scores.begin(), scores.end());
        // if (allOnes||allZeros)
        //     max = s.length() - 1;
        return max;
    }
};