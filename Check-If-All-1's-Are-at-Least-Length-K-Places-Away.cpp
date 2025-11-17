class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int trace=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                if(trace<k&&trace>=0)
                {
                    return false;
                }
                trace=0;
            }else if(trace !=-1)
            {
                trace++;
            }
            
        }
        return true;
    }
};