/*
String Encode and Decode
Solved 
Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement encode and decode

Example 1:

Input: ["neet","code","love","you"]

Output:["neet","code","love","you"]
Example 2:

Input: ["we","say",":","yes"]

Output: ["we","say",":","yes"]
Constraints:

0 <= strs.length < 100
0 <= strs[i].length < 200
strs[i] contains only UTF-8 characters.

*/

class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size()==0) return "empty";
        string result="";
        for(int i=0;i<strs.size();i++)
        {
            result+=strs[i];
            if(i!=strs.size()-1)
            result+="/";
        }
        return result;
    }

    vector<string> decode(string s) {
    if(s=="") return {""};
    if(s=="empty") return {};
    string word=s;
     char delimiter = '/';
    std::vector<std::string> parts;
    size_t start = 0;
    size_t end = word.find(delimiter);

    while (end != std::string::npos) {
        parts.push_back(word.substr(start, end - start));
        start = end + 1;
        end = word.find(delimiter, start);
    }
    parts.push_back(word.substr(start));  // Last part
return parts;

   
    }
};
