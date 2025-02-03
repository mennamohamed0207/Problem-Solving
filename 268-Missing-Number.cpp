class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1&&nums[0]==1) return 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i)
            return i;
        }
        return n;
    }
};