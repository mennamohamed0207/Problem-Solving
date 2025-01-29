class Solution {
public:
    int countAsterisks(string s) {
        int result=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='|')
            {
                i++;
                while(s[i]!='|')
                    i++;
            }
            if(s[i]=='*')
                result++;
        }
        return result;
    }
};