class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2) {
        for (int i = 0; i < str1.length(); i++) {
            int index = (str2.length() - str1.length()) - 2 + i;
            if(index<0) index=str2.length()-1;
            if (index >= 0) {
                if (str1[i] != str2[i] || str1[i] != str2[index])
                    return false;
            } else
                return false;
        }
        cout<<str1<<" "<<str2<<endl;
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int output = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                string& str1 = words[i];
                string& str2 = words[j];
                if (words[i].size() > words[j].size()) continue;

               if (str2.find(str1) == 0 &&
                    str2.rfind(str1) == str2.size() - str1.size()) {
                    ++output;
                }
            }
        }
        return output;
    }
};