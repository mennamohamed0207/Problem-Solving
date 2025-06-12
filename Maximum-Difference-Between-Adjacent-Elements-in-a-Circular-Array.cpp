class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int result = -1;
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                if (abs(nums[i] - nums[i + 1]) > result)
                    result = abs(nums[i] - nums[i + 1]);
            } else {
                if (abs(nums[i] - nums[0]) > result)
                    result = abs(nums[i] - nums[0]);
            }
        }
        return result;
    }
};