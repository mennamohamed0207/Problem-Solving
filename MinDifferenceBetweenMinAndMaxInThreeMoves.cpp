/*
You are given an integer array nums.

In one move, you can choose one element of nums and change it to any value.

Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

 

Example 1:

Input: nums = [5,3,2,4]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 2 to 3. nums becomes [5,3,3,4].
In the second move, change 4 to 3. nums becomes [5,3,3,3].
In the third move, change 5 to 3. nums becomes [3,3,3,3].
After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.
*/
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minDifference(std::vector<int>& nums) {
        if (nums.size() <= 4) {
            // If there are 4 or fewer elements, we can make all elements equal in at most 3 moves.
            return 0;
        }
        
        std::sort(nums.begin(), nums.end());
        std::vector<int> result;
        
        // We have the following possibilities:
        // 1. Change the three largest elements to the fourth largest element.
        result.push_back(nums[nums.size() - 4] - nums[0]);
        
        // 2. Change the two largest elements and the smallest element.
        result.push_back(nums[nums.size() - 3] - nums[1]);
        
        // 3. Change the largest element and the two smallest elements.
        result.push_back(nums[nums.size() - 2] - nums[2]);
        
        // 4. Change the three smallest elements to the fourth smallest element.
        result.push_back(nums[nums.size() - 1] - nums[3]);
        
        return *std::min_element(result.begin(), result.end());
    }
};
