/*You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0
 

Constraints:

1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.*/
//Beats 9.47%
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        unordered_map<char, int> store;
        for (int i = 0; i < jewels.length(); i++) {
            store[jewels[i]]++;
        }
        for (int i = 0; i < stones.length(); i++) {
            if (store[stones[i]] > 0) {
                count++;
            }
        }
        return count;
    }
};
/*
Learned from this problem: 
std::count() returns the number of occurrences of an element in a given range. Returns the number of elements in the range [first, last) that compare equal to val.
Example:
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int arr[] = { 3, 2, 1, 3, 3, 5, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<
 
        "  Number of times 3 appears : "
    << count(arr, arr + n, 3);
 
    return 0;
}

*/