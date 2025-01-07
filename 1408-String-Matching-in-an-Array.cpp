class Solution {
public:
bool isSubstring(string source,string dest)
{
    return dest.find(source) !=std::string::npos;
}

    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string>answer;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(i!=j&&isSubstring(words[i],words[j]))
                   { answer.insert(words[i]);
                   }
            }
        }

        return std::vector<std::string>(answer.begin(), answer.end()); 
    }
};