1class Solution {
2public:
3    bool canMakeArithmeticProgression(vector<int>& arr) {
4        sort(arr.begin(),arr.end());
5        int diff=(arr[0]-arr[1]);
6        for(int i=0;i<arr.size();i++)
7        {
8            if(i+1<=arr.size()-1&&(arr[i]-arr[i+1])!=diff)
9            return false;
10            
11        }
12        return true;
13    }
14};