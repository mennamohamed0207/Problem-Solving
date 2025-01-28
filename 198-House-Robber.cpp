class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size());
        dp[0]=nums[0];
        if(nums.size()>1)
        dp[1]=nums[1];
        for(int i=2;i<nums.size();i++)
        {
            int k=2;
            while(i-k>=0)
            {dp[i]=max(dp[i],nums[i]+dp[i-k]);
            k++;
            }
        }
        int max_element=*std::max_element(dp.begin(),dp.end());
        return max_element;
    }
};