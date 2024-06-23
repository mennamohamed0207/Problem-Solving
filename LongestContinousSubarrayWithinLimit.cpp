/*
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= limit <= 109
*/

//My own solution passed 37/61 test cases but memory limit exceeded
class Solution {
public:
   int result;
    Solution() {
        result=INT_MIN;
    }
    bool hasValidLimit(vector<int> arr,int start,int end, int limit) {
        for (int i = start; i <= end; i++) {
            for (int j = start; j <= end; j++) {
                if (abs(arr[i] - arr[j]) > limit)
                    // cout<<abs(arr[i] - arr[j])<<" ";
                    return false;
            }
        }
        return true;
    }
    /void printSubArrays(vector<int> arr, int start, int end, int limit) {
        // Stop if we have reached the end of the array
        if (end == arr.size())
            return;
        // Increment the end point and start from 0
        else if (start > end)
            printSubArrays(arr, 0, end + 1, limit);
        // Print the subarray and increment the starting point
        else {
            // calculate the diff
            if (hasValidLimit(arr,start,end, limit)) {
                result=max(end-start+1,result);
                // cout<<"///////"<<" ";
                
            }
            // cout << "[";
            // for (int i = start; i < end; i++)
            //     cout << arr[i] << ", ";
            // cout << arr[end] << "]" << endl;
            printSubArrays(arr, start + 1, end, limit);
        }
        return;
    }
    int longestSubarray(vector<int>& nums, int limit) {
        printSubArrays(nums, 0, 0, limit);

       return result;
    }
};
//Second Solution Accepted one with the help of chatgpt
int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int start = 0, result = 0;
        
        for (int end = 0; end < nums.size(); ++end) {
            // Maintain the maxDeque and minDeque
            while (!maxDeque.empty() && nums[end] > maxDeque.back()) maxDeque.pop_back();
            while (!minDeque.empty() && nums[end] < minDeque.back()) minDeque.pop_back();
            
            maxDeque.push_back(nums[end]);
            minDeque.push_back(nums[end]);
            
            // Check if the current window is valid
            while (!maxDeque.empty() && !minDeque.empty() && (maxDeque.front() - minDeque.front() > limit)) {
                // Shrink the window from the left
                if (nums[start] == maxDeque.front()) maxDeque.pop_front();
                if (nums[start] == minDeque.front()) minDeque.pop_front();
                ++start;
            }
            
            // Update the result for the longest valid subarray
            result = max(result, end - start + 1);
        }
        
        return result;
    }