class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
     vector<string>combinations;
            //  string cur(nums.size(), '0');
     dfs("",0,combinations,nums[0].length());
     sort(nums.begin(),nums.end());
        cout<<"nums"<<endl;
     for(int i=0;i<nums.size();i++)
     {
        // cout<<nums[i]<<" ";
        if(combinations[i]!=nums[i])
        return combinations[i];
     }   
     if(nums.size()< combinations.size())
     {
        return combinations[nums.size()];
     }
     return "";
    }
    void dfs(string s,int i,vector<string>&combinations,int n)
    {
        if(i==n)
        {
            combinations.push_back(s);
            // cout<<s<<" ";
            return ;

        }
        dfs(s+"0",i+1,combinations,n);
        dfs(s+"1",i+1,combinations,n);

    }
};