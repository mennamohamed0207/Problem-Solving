/*Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100
*/
//First Solution but it didn't get accepted
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        vector<int> result;
        int maxFreq = 0;
        int value = 0;
        while (result.size() != nums.size()) {
            for (const auto& d : freq) {
                cout << d.first << " " << d.second << endl;
                if (maxFreq < d.second) {
                    if (maxFreq == d.second) {
                        if (value > d.first)
                        {
                            maxFreq = d.second;
                            value = d.first;
                        }
                    }else{
                         maxFreq = d.second;
                         value = d.first;
                    }
                }
            }
            freq[value]=0;
            cout<<maxFreq<<" ///////////"<<endl;
            while (maxFreq != 0) {
                result.push_back(value);
                maxFreq--;
                // break;
            }
            value=0;
        }
        // vector<int> final_result;
        //  for(int i=nums.size()-1;i>=0;i--)
        // {
        //    final_result.push_back()
        // }
        reverse(result.begin(),result.end());

        return result;
    }
};
//Second Solution Accepted
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
         unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b]) {
                return a > b;
            }
            return freq[a] < freq[b];
        });

        return nums;
    }
};