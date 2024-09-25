/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)*/

//First Solution time limit exceeded
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            product=1;
            for(int j=0;j<nums.size();j++)
            {
                if(i==j) continue;
                product*=nums[j];
            }
            result.push_back(product);
        }
       
        return result;
    }
};
//Second Solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
          int n=nums.size();
        vector<int> result(n);
        vector <int>leftProduct(n);
        vector <int>rightProduct(n);
        leftProduct[0]=1;
        for (int i = 1; i < nums.size(); i++) {
          leftProduct[i]=leftProduct[i-1]*nums[i-1];
        }
        rightProduct[nums.size()-1]=1;
      
         for (int i = n-2; i >=0; i--) {
          rightProduct[i]=rightProduct[i+1]*nums[i+1];
        }
         for (int i = 0; i < nums.size(); i++) {
            result[i]=leftProduct[i]*rightProduct[i];
        }
       
        return result;
    }
};