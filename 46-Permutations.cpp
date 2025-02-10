class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int>formed;
        dfs(nums,result,0);
         
    return result;
    }
    void dfs(vector<int>nums,vector<vector<int>>& result,int i)
    {
        if(i==nums.size())
        {
            result.push_back(nums);
            return ;
        }
         for (int j = i; j < nums.size(); j++) {  
            swap(nums[i], nums[j]);

            dfs(nums,result, i + 1);

            // Backtracking
            swap(nums[i], nums[j]);
        }


    }
};