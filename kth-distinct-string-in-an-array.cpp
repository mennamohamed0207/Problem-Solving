/*
A distinct string is a string that is present only once in an array.

Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".

Note that the strings are considered in the order in which they appear in the array.

 

Example 1:

Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned. 
Example 2:

Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"
Explanation:
All strings in arr are distinct, so the 1st string "aaa" is returned.
Example 3:

Input: arr = ["a","b","a"], k = 3
Output: ""
Explanation:
The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".
 

Constraints:

1 <= k <= arr.length <= 1000
1 <= arr[i].length <= 5
arr[i] consists of lowercase English letters.
*/
//Beats 5.17%
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        bool find_duplicate=false;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] == arr[j] && arr[i] != "0") {
                    arr[j] = "0";
                    // arr[i] = "0";
                    find_duplicate=true;
                }
            }
            if(find_duplicate)
            {
                arr[i]="0";
                find_duplicate=false;
            }
        }
        vector<string> distinct;
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
            if (arr[i] != "0")
                distinct.push_back(arr[i]);
        }

        if (k > distinct.size() || distinct[k - 1] == "0") {
            return "";
        } else
            return distinct[k - 1];
    }
};
//Beats 37%
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>map;
        for(int i=0;i<arr.size();i++)
        {
            map[arr[i]]++;
        }
        vector<string> distinct;
        for(int i=0;i<arr.size();i++)
        {
            if(map[arr[i]]==1)
            {
                distinct.push_back(arr[i]);
                cout<<arr[i]<<" ";
            }
        }
        if(k<=distinct.size())
        {
            return distinct[k-1];

        }else{
            return "";
        }
       
    }
};