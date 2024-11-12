// class Solution {
// public:
//     vector<int> maximumBeauty(vector<vector<int>>& items,
//                               vector<int>& queries) {
//         unordered_map<int, int> map;
//         vector<int> answer;
//         vector<int> prices;
//         for (int i = 0; i < items.size(); i++) {
//             if (items[i][1] > map[items[i][0]])
//                 map[items[i][0]] = items[i][1];
//             prices.push_back(items[i][0]);
//         }
//         // sort(prices.begin(), prices.end());
//         for (int i = 0; i < queries.size(); i++) {
//             int maxBeauty=0;
//             for (int j = 0; j < prices.size(); j++) {
//                 if(prices[j]<=queries[i]&&maxBeauty<map[prices[j]])
//                      maxBeauty=map[prices[j]];
//                 if(prices[j]==queries[i])
//                     break;
//             }
//             answer.push_back(maxBeauty);
//         }
//         return answer;
//     }
// };
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        unordered_map<int, int> map;
        vector<int> answer;
        vector<int> prices;
        
        // Step 1: Track the maximum beauty for each unique price.
        for (const auto& item : items) {
            if (item[1] > map[item[0]]) {
                map[item[0]] = item[1];
            }
        }

        // Step 2: Prepare sorted unique prices with max beauty prefix.
        for (const auto& [price, beauty] : map) {
            prices.push_back(price);
        }
        sort(prices.begin(), prices.end());

        // Step 3: Build prefix max array for maximum beauty at each price.
        vector<int> maxBeauty(prices.size());
        maxBeauty[0] = map[prices[0]];
        for (int i = 1; i < prices.size(); ++i) {
            maxBeauty[i] = max(maxBeauty[i - 1], map[prices[i]]);
        }

        // Step 4: For each query, use binary search to find max beauty.
        for (int q : queries) {
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
