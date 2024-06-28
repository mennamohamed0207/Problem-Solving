class Solution {
public:
    bool is_number(const std::string& s) {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it))
            ++it;
        return !s.empty() && it == s.end();
    }
    bool isIsomorphic(string s, string t) {
        if(!is_number(s))
        {vector<char> map(26, '0');
        if (s.length() != t.length())
            return false;
        for (int i = 0; i < s.length(); i++) {

            if (map[s[i] - 97] == '0')
                map[s[i] - 97] = t[i];
            else if (map[s[i] - 97] != t[i])
                return false;
        }
        vector<char> map2(26, '0');

        for (int i = 0; i < s.length(); i++) {

            if (map2[t[i] - 97] == '0')
                map2[t[i] - 97] = s[i];
            else if (map2[t[i] - 97] != s[i])
                return false;
        }
        return true;
        }else
        {// for numbers
        vector<char> map_num(10, 'a');

        for (int i = 0; i < s.length(); i++) {

            if (map_num[s[i] - 48] == 'a')
                map_num[s[i] - 48] = t[i];
            else if (map_num[s[i] - 48] != t[i])
                return false;
        }
        vector<char> map_num2(10, 'a');

        for (int i = 0; i < s.length(); i++) {

            if (map_num2[t[i] - 48] == 'a')
                map_num2[t[i] - 48] = s[i];
            else if (map_num2[t[i] - 48] != s[i])
                return false;
        }

        return true;}
    }
};