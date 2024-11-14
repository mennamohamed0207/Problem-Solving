// class Solution {
// public:
//     // long long countFairPairs(vector<int>& nums, int lower, int upper) {
//     //     sort(nums.begin(),nums.end());
//     //     int begin=0;
//     //     int end=nums.size()-1;
//     //     long long result = 0;
       
//     //     do{
//     //         long long sum=nums[begin]+nums[end];
//     //         if (sum >= lower && sum <= upper)
//     //                 result++;
          
//     //         else {
//     //             result=end-begin+1;
//     //             break;
//     //         }
//     //         begin++;
//     //         end--;

//     //     } while(begin<end);
//     //     return result;
//     // }
//     // long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
//     //     std::sort(nums.begin(), nums.end());
//     //     long long result = 0;
        
//     //     for (int i = 0; i < nums.size(); i++) {
//     //         int left = i + 1;
//     //         int right = nums.size() - 1;

//     //         // Find the smallest index where nums[j] >= lower - nums[i]
//     //         int lower_bound = std::lower_bound(nums.begin() + left, nums.end(), lower - nums[i]) - nums.begin();
//     //         // Find the largest index where nums[j] <= upper - nums[i]
//     //         int upper_bound = std::upper_bound(nums.begin() + left, nums.end(), upper - nums[i]) - nums.begin() - 1;

//     //         // Count valid pairs for the current i if there's a valid range
//     //         if (lower_bound <= upper_bound) {
//     //             result += upper_bound - lower_bound + 1;
//     //         }
//     //     }
        
//     //     return result;
//     // }
//     long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
//         std::sort(nums.begin(), nums.end());
//         long long result = 0;

//         for (int i = 0; i < nums.size() - 1; ++i) {
//             int begin = i + 1;
//             int end = nums.size() - 1;

//             // Find the smallest index where nums[begin] + nums[i] >= lower
//             while (begin <= end && nums[i] + nums[begin] < lower) {
//                 begin++;
//             }

//             // Find the largest index where nums[end] + nums[i] <= upper
//             while (begin <= end && nums[i] + nums[end] > upper) {
//                 end--;
//             }

//             // Count all valid pairs for this fixed i
//             if (begin <= end) {
//                 result += end - begin + 1;
//             }
//         }

//         return result;
//     }

// };
// /*
// 47 out 54 testcase but time limit exceeded
// class Solution {
// public:
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         sort(nums.begin(),nums.end());
//         int begin=0;
//         int end=nums.size()-1;
//         long long result = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i+1; j < nums.size(); j++) {
//                 long long sum = nums[i] + nums[j];
//                 if (sum >= lower && sum <= upper)
//                     result++;
//             }
//         }
//         return result;
//     }
// };
// */
class Solution {
public:
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        long long ans = 0;
        sort(v.begin(), v.end());

        for (int i = 0; i < v.size() - 1; i++) {
            auto up = upper_bound(v.begin() + i + 1, v.end(), upper - v[i]);
            auto low = lower_bound(v.begin() + i + 1, v.end(), lower - v[i]);
            ans += (up - low);
        }
        return ans;
    }
};