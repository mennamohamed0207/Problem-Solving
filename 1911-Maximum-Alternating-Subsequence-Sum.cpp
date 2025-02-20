class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sumEven=0;
        long long sumOdd=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            long long tempEven=max(sumOdd+nums[i],sumEven);
            long long tempOdd=max(sumEven-nums[i],sumOdd);
            sumOdd=tempOdd;
            sumEven=tempEven;
        }
        return sumEven;
    }
};