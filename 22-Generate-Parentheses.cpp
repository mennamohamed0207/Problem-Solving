class Solution {
public:
    bool valid (string s)
    {
        int open =0;
        for (char c:s)
        {
            if(c=='(')
            open ++;
            else  {
                open--;
            }
            if(open<0) return false;

        }
        return open==0;
    }
    void dfs(string s,vector<string>&result,int n )
    {
        if(s.length()==2*n)
        {
            if(valid(s)) 
            result.push_back(s);
            return ;
        }else{
        dfs('('+s,result,n);
        dfs(')'+s,result,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        dfs(\\,result,n);
        return result;
    }
};