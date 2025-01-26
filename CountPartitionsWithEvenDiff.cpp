class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int leftSum=0;
        int rightSum=0;
        int totalSum=0;
        int partition=0;
        for(int i=0;i<nums.size();i++)
            {
                totalSum+=nums[i];
            }
        rightSum=totalSum;
         for(int i=0;i<nums.size()-1;i++)
            {
               leftSum+=nums[i];
                rightSum-=nums[i];
                int diff=abs(leftSum-rightSum);
                if(diff%2==0)
                    partition++;
            }
        return partition;
    }
};