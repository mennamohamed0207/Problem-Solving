class Solution {
public:
    long long fact(int n) {
        long long factorial = 1;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }
        return factorial;
    }

    long long countBadPairs(vector<int>& nums) {
        // Brute Force O(n^2)
        // TLE --> 56/65
        /*
        long long result=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(j-i!=nums[j]-nums[i])
                result++;
            }
        }
        return result;
        */
        // 3!-3
        unordered_map<int, int> map;
        long long goodPairs = 0;
        int n = nums.size();

        long long totalPairs = (1LL * n * (n - 1)) / 2;
        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i] - i;
            goodPairs += map[key]; // Each previous occurrence forms a good pair
            map[key]++;   // Increment frequency
        }

        return totalPairs - goodPairs;
    }
};