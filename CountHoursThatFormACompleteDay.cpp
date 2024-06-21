/*
Given an integer array hours representing times in hours, return an integer denoting the number of pairs i, j where i < j and hours[i] + hours[j] forms a complete day.

A complete day is defined as a time duration that is an exact multiple of 24 hours.

For example, 1 day is 24 hours, 2 days is 48 hours, 3 days is 72 hours, and so on.

 

Example 1:

Input: hours = [12,12,30,24,24]

Output: 2

Explanation:

The pairs of indices that form a complete day are (0, 1) and (3, 4).

Example 2:

Input: hours = [72,48,24,3]

Output: 3

Explanation:

The pairs of indices that form a complete day are (0, 1), (0, 2), and (1, 2).

 

Constraints:

1 <= hours.length <= 100
1 <= hours[i] <= 109
*/
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int result=0;
        for(int i=0;i<hours.size();i++)
        {
            for(int j=i+1;j<hours.size();j++)
            {
                if(((hours[i]+hours[j])%24==0))
                {
                    result++;
                    
                }
            }
        }
        return result;
    }
};


//optimal solution 
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
       std::unordered_map<long long, long long> remainder_count;
        long long pairs = 0;
        long long complete_day = 24;

        for (long long hour : hours) {
            long long remainder = hour % complete_day;
            long long complement = (complete_day - remainder) % complete_day;
            
            // If complement has been seen before, it forms a pair
            if (remainder_count.find(complement) != remainder_count.end()) {
                pairs += remainder_count[complement];
            }

            // Increase the count of the current remainder
            remainder_count[remainder]++;
        }

        return pairs;
    }
};