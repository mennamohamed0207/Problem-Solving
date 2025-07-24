class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int num:nums)
        {
            map[num]++;
            if(map[num]==2)
            return num;
        }
        return -1;
    }
};