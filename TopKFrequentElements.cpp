/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
//beats 68%
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        for (int i = 0; i < k; i++) {
            int max=0;
            int entry =0;
            for (auto pair : map) {
                if (pair.second > max) {
                    max = pair.second;

                    cout << pair.first << " " << pair.second << endl;
                    entry = pair.first;
                }
            }
            map[entry]=0;
            result.push_back(entry);
        }

        return result;
    }
};