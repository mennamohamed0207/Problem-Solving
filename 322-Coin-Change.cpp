class Solution {
public:
    unordered_map<int,int>dp;
    int dfs(vector<int>& coins, int amount) {
        if(amount==0)
        return 0;
        if(dp.find(amount)!=dp.end())
        return dp[amount];
        int res = INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            if(amount-coins[i]>=0)
            {
                int result = dfs( coins,amount - coins[i]);
                if (result != INT_MAX) {
                    res = min(res, 1 + result);
                }
            }
        }
        dp[amount]=res;
        return res;
    }
    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs( coins,amount);
        return minCoins == INT_MAX ? -1 : minCoins;
    }
};