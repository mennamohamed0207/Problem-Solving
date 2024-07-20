//https://leetcode.com/contest/biweekly-contest-135/problems/minimum-array-changes-to-make-differences-equal/description/
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int changes=0;
        int x=abs(nums[0]-nums[nums.size()-1]);
        vector<int>choosediff;
        for(int i=0;i<nums.size();i++)
        {
            choosediff.push_back(nums[i]);
        }
        sort(choosediff.begin(),choosediff.end());
        for(int i=0;i<nums.size();i++)
        {
            int check=abs(nums[i]-nums[nums.size()-i-1]);
            if(check!=x)
            {
              if((nums[i]+(x-check))<=k)
              {
                nums[i]+=(x-check);
                changes++;
              }else{
                nums[i]=k;
                nums[nums.size()-i-1]=x-k;
                 changes++;
              }
            }
        }
        return changes;
    }
};



class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        unordered_map<int, int> diff;
        int minChanges = 0;
        // int x = 0;
        vector<int> x;
        for (int i = 0; i < nums.size() / 2; ++i) {

            diff[abs(nums[i] - nums[nums.size() - i - 1])]++;
            if (nums[i] + nums[nums.size() - i - 1] > k) {
                x.push_back(abs(nums[i] - nums[nums.size() - i - 1]));
                minChanges++;
            }
        }
        int maxFreq = 0;
        int first = 0;
        for (const auto& d : diff) {
            cout << d.first << " ";
            if (maxFreq < d.second) {
                maxFreq = d.second;
                first = d.first;
            }
        }
        cout<<first;
        for (int i = 0; i < x.size(); i++) {

            if (x[i] == first)
                minChanges--;
        }
        minChanges += (nums.size() / 2 - maxFreq);
        return minChanges;
    }
};