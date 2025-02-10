class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      set<vector<int>> result;
        vector<int> formed;
        dfs(nums, formed, result, 0);
        return vector(result.begin(),result.end());
    }
    void dfs(vector<int> nums, vector<int> formed, set<vector<int>>& result,
             int i) {
        if (formed.size() == nums.size()||i==nums.size()) {
                    sort(formed.begin(),formed.end());

            result.insert(formed);
            return;
        }
        // if(result.find(formed)!=result.end())
        formed.push_back(nums[i]);

        dfs(nums, formed, result, i + 1);
        formed.pop_back();
        dfs(nums, formed, result, i +1);
        sort(formed.begin(),formed.end());
            result.insert(formed);
    }
};