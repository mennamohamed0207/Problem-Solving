class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (i < nums.size()-1 && nums[i] % 2 == nums[i+1] % 2 )
                return false;
        }
        if (nums.size() > 2 &&
            nums[nums.size() - 2] % 2 == nums[nums.size() - 1] % 2)
            return false;
        return true;
    }
};