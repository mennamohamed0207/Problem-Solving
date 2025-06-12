class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        vector<int> diff;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i < n - 1)
                diff.push_back(abs(nums[i] - nums[i + 1]));
            else diff.push_back(abs(nums[i]-nums[0]));
        }
        sort(diff.begin(), diff.end());
        return diff[n - 1];
    }
};