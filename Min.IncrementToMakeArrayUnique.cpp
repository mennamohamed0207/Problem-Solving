

//First Solution O(n^2) 53/63 test cases passed 
//time limit exceeded
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int moves = 0;
        bool flag = false;
        while (!flag) {
            flag = true;
            for (int i = 0; i < nums.size(); i++) {
                for (int j = 0; j < nums.size(); j++) {
                    if (nums[i] == nums[j] && i != j) {
                        nums[i]++;
                        moves++;
                    }
                }
            }
            for (int i = 0; i < nums.size(); i++) {
                for (int j = 0; j < nums.size(); j++) {
                    if (nums[i] == nums[j] && i != j) {
                        flag = false;
                    }
                }
            }
        }
        return moves;
    }
};
//Accepted Solution with the help of chatgpt 
class Solution {
public:
     int minIncrementForUnique(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int moves = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                int increment = nums[i - 1] + 1 - nums[i];
                moves += increment;
                nums[i] = nums[i - 1] + 1;
            }
        }

        return moves;
    }
};