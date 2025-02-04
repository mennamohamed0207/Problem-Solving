class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxPossibleSum = 0;
        int n = nums.size();
        int possibleSum = nums[0];
      
        for (int i = 1; i < n; i++) {
            
            if (nums[i] <= nums[i - 1]) {
                maxPossibleSum=max(maxPossibleSum,possibleSum);
                possibleSum=0;
            } 
            possibleSum+=nums[i];
        }
     
        return max(maxPossibleSum,possibleSum);
    }
};