class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int>map;
        for(char c:s)
        {
            map[c]++;
            if(map[c]==2)
            {
                return c;
            }
        }
        return 'c';
    }
};