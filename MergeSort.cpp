#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void merge(vector<int>& nums, int begin, int mid, int end) {
        int leftSize = mid - begin + 1;
        int rightSize = end-mid ;
        int* leftArr = new int[leftSize];
        int* rightArr = new int[rightSize];
        for (int i = 0; i < leftSize; i++) {
            leftArr[i] = nums[begin + i];
        }
        for (int i = 0; i < rightSize; i++) {
            rightArr[i] = nums[mid + 1 + i];
        }
        int i = 0;
        int j = 0;
        int k = begin;
        while (i < leftSize && j < rightSize) {
            if (leftArr[i] < rightArr[j]) {
                nums[k] = leftArr[i];
                k++;
                i++;
            } else {
                nums[k] = rightArr[j];
                k++;
                j++;
            }
        }
        while (i < leftSize) {
            nums[k] = leftArr[i];
            i++;
            k++;
        }
        while (j < rightSize) {
            nums[k] = rightArr[j];
            j++;
            k++;
        }
    }
   // Divide the array into two subarrays,
        //sort them and merge them 
        void mergeSort(vector<int>& arr, int l, int r) 
        {
        if (l < r) {
            // m is the point where the array is divided into two subarrays
            int m = l + (r - l) / 2;

            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            // Merge the sorted subarrays
            merge(arr, l, m, r);
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 5, 2, 3, 1 };
    vector<int> result = s.sortArray(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}