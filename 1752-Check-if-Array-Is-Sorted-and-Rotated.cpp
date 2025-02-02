class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int violate = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) // Check circular condition
                violate++;
        }
        
        return violate <= 1; // At most one violation means it can be a rotated sorted array
    }
};
