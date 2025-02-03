class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());

        int n = nums.size();
        if (n == 1 && nums[0] == 1)
            return 0;
        for (int i = 0; i < n; i++) {
           if(num_set.find(i)==num_set.end())
                return i;
        }
        return n;
    }
};