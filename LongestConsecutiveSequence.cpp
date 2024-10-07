/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/
//Beats 35%
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;

        sort(nums.begin(), nums.end());
       int result=1;
        int count = 1;
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " " << endl;
            if (i <= nums.size() - 2) {
                if (nums[i] == nums[i + 1])
                    continue;
                if (nums[i + 1] - nums[i] == 1) {
                    count++;
                } else {
                    result=max(count,result);
                    count = 1;
                }
            }
        }
        return max(result,count);
    }
};