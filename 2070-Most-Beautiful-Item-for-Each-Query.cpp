class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        unordered_map<int, int> map;
        vector<int> answer;
        vector<int> prices;
        for (int i = 0; i < items.size(); i++) {
            if (items[i][1] > map[items[i][0]])
                map[items[i][0]] = items[i][1];
            prices.push_back(items[i][0]);
        }
        sort(prices.begin(), prices.end());
        vector<int>maxBeauty(prices.size());
        maxBeauty[0]=map[prices[0]];
        for(int i=1;i<prices.size();i++)
        {
            maxBeauty[i]=max(maxBeauty[i-1],map[prices[i]]);
        }
         for (int q : queries) {
            //get the element in the prices that is strictly greater than q
            auto it = upper_bound(prices.begin(), prices.end(), q);
            if (it == prices.begin()) {
                answer.push_back(0); // No price is <= query price
            } else {
                answer.push_back(maxBeauty[it - prices.begin() - 1]);
            }
        }
        return answer;
    }
};