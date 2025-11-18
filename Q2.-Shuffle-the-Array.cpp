class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>result(nums.size());
        int j=0;
        for(int i=0;i<2*n;i+=2)
        {
            result[i]=nums[j];
            result[i+1]=nums[j+n];
            j++;
        }
        return result;
    }
};