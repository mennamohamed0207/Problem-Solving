/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int max_element1 = *std::max_element(nums1.begin(), nums1.end());
        vector<int> map_nums1(max_element1+1, 0);
        int max_element2 = *std::max_element(nums2.begin(), nums2.end());
        vector<int> map_nums2(max_element2+1, 0);

        for (int i = 0; i < nums1.size(); i++) {
            map_nums1[nums1[i]]++;
        }
        for (int j = 0; j < nums2.size(); j++) {
            map_nums2[nums2[j]]++;
        }
        int smaller;
        if (max_element1 < max_element2) {
            smaller = max_element1;
        } else
            smaller = max_element2;
        for (int j = 0; j < smaller+1; j++) {
            if(map_nums1[j]!=0&&map_nums2[j]!=0&&map_nums1[j]!=map_nums2[j])
            {
                int enter=min(map_nums1[j],map_nums2[j]);
                while(enter>0)
                {
                    result.push_back(j);
                    enter--;
                }
            }
            if(map_nums1[j]==map_nums2[j])
            {
                cout<<map_nums1[j];
                cout<<"smaller"<<smaller;
                while(map_nums1[j]>0)
                {
                    result.push_back(j);
                    map_nums1[j]--;
                }
            }
        }
        return result;
    }
};