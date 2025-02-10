class Solution {
public:
 string mapping[10] = {\\,    \\,    \abc\,  \def\, \ghi\,
                              \jkl\, \mno\, \pqrs\, \tuv\, \wxyz\};
    vector<string> letterCombinations(string digits) {
         if(digits.length()==0) return {};
                              vector<string>combination;
                              string formed;
        dfs(digits,combination,formed,0);
        return combination;
    }
    void dfs(string digits,vector<string>&combination,string formed,int i)
    {
        if(i==digits.length())
        {
            combination.push_back(formed);
            return ;

        }
        string chars=mapping[digits[i]-'0'];
        for(char c:chars)
        {
            // formed+=c;
            dfs(digits,combination,formed+c,i+1);
        }
    }
};