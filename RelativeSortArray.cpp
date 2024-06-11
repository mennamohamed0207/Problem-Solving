/* Easy
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
 

Constraints:

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.
*/


#include <algorithm>
#include <iostream>
#include <vector>
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector <int> result;
        int k=0;
        //make hash map to count the frequency of the numbers in arr1
        unordered_map<int, int> freqeuncies;
        for (int i=0;i<arr1.size();i++)
        {
            freqeuncies[arr1[i]]=0;
        }
        for (int i=0;i<arr1.size();i++)
        {
            freqeuncies[arr1[i]]++;

        }
        //loop on the arr2 and put the numbers that are in arr1,arr2 with same count of numbers
        for (int i=0;i<arr2.size();i++)
        {
            auto it = freqeuncies.find(arr2[i]);

            if (it != freqeuncies.end()) {
                int repeat=freqeuncies[arr2[i]];
                                        std::cout<<"what ";

                while(repeat!=0)
                {
                result.push_back(arr2[i]);
                k++;
                repeat--;
                }
            }
        }
        vector <int>rest;
        //make an array that has the numbers that doesn't exist in arr2 but exist in arr1
        for(int i=0;i<arr1.size();i++)
        {
           auto  it = std::find(arr2.begin(), 
                 arr2.end(), arr1[i]);
            if (it == arr2.end()) {
                rest.push_back(arr1[i]);
            }
        }
        //sort that array and then put it in the end of the result array
        sort(rest.begin(), rest.end());
        for(int i=0;i<rest.size();i++)
        {
            result.push_back(rest[i]);
        } 
        
return result;
    }
};