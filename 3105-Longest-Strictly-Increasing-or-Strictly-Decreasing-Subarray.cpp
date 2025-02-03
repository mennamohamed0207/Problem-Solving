class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxDesiredLengthInc=1;
        int desiredLengthInc=1;
        int maxDesiredLengthDec=1;
        int desiredLengthDec=1;

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i<n-1&&nums[i]<nums[i+1])
                desiredLengthInc++;
            else  desiredLengthInc=1;

            if(desiredLengthInc>maxDesiredLengthInc) {
                    maxDesiredLengthInc=desiredLengthInc;
            }
            if(i<n-1&&nums[i]>nums[i+1])
                desiredLengthDec++;
            else                     desiredLengthDec=1;

            if(desiredLengthDec>maxDesiredLengthDec) {
                    maxDesiredLengthDec=desiredLengthDec;
            }

        }
        if(maxDesiredLengthInc>maxDesiredLengthDec)
        return maxDesiredLengthInc;
        else return maxDesiredLengthDec;
    }
};