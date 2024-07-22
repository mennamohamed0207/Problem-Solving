/*
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
 

Constraints:

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.
*/
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> heightNamePairs;

        for (int i = 0; i < n; i++) {
            heightNamePairs.push_back({heights[i], names[i]});
        }

        // Sort pairs based on height in descending order
        sort(heightNamePairs.begin(), heightNamePairs.end());

        vector<string> final_names;
        for (int i = n-1; i >=0; i--) {
            final_names.push_back(heightNamePairs[i].second);
        }

        return final_names;
    }
};
