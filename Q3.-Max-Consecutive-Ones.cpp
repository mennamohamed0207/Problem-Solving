class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_conseq = 0;
        int curr_conseq = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                curr_conseq++;
            } else {
                if (curr_conseq > max_conseq)
                    max_conseq = curr_conseq;
                curr_conseq = 0;
            }
        }
         if (curr_conseq > max_conseq)
                max_conseq = curr_conseq;
        return max_conseq;
    }
};