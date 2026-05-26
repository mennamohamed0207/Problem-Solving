1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        unordered_map<char, int> specialChar;
5        set<char> specialChar_set;
6        for (int i = 0; i < word.length(); i++) {
7            specialChar[word[i]]++;
8            if (isupper(word[i])) {
9                if (specialChar[word[i]] != 0 &&
10                    specialChar[tolower(word[i])] != 0) {
11                    specialChar_set.insert(tolower(word[i]));
12                }
13            }else{
14                if (specialChar[word[i]] != 0 &&
15                    specialChar[toupper(word[i])] != 0) {
16                    specialChar_set.insert(word[i]);
17                }
18            }
19        }
20        return specialChar_set.size();
21    }
22};