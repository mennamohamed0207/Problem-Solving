class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int diff=0;
        unordered_map<char,int>s1_map;
        unordered_map<char,int>s2_map;
        for(int i=0;i<s1.length();i++)
        {
            s1_map[s1[i]]++;
            s2_map[s2[i]]++;
        }
        for(auto pair:s1_map)
        {
            if(s2_map[pair.first]!=pair.second)
            return false;
        }
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i]) 
                diff++;
        }
        return diff==2;
    }
};