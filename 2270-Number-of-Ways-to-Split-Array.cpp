class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> sumR(nums.size());
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                sumR[0] = nums[0];
            } else {
                sumR[i] = sumR[i - 1] + nums[i];
            }
            sum += nums[i];
        }
        int output=0;
        for (int i = 0; i < nums.size()-1; i++) {
            if (sumR[i] >= (sum - sumR[i]))
                output++;
        }
        return output;

    }
};