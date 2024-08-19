/*You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word so that the frequency of every letter present in word is equal.

Return true if it is possible to remove one letter so that the frequency of all letters in word are equal, and false otherwise.

Note:

The frequency of a letter x is the number of times it occurs in the string.
You must remove exactly one letter and cannot choose to do nothing.
 

Example 1:

Input: word = "abcc"
Output: true
Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.
Example 2:

Input: word = "aazz"
Output: false
Explanation: We must delete a character, so either the frequency of "a" is 1 and the frequency of "z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.
 

Constraints:

2 <= word.length <= 100
word consists of lowercase English letters only.*/
//Beats 100%
class Solution {
public:
    int mostFrequentNumber(const std::vector<int>& vec) {
        std::unordered_map<int, int> frequencyMap;
        int nonZero=0;
        vector<int>non;
        // Count the frequency of each number
        for (int num : vec) {
            cout<<num<<" ";
            if(num!=0)
            {nonZero++;
            non.push_back(num);
            frequencyMap[num]++;
            }
        }
        if(nonZero==2)
        {
            if(non[0]==1||non[1]==1)
            return -1;
        }
        if(nonZero==3)
        {
            if((non[0]==1&&non[1]==1&&non[2]!=1)&&
            (non[0]!=1&&non[1]==1&&non[2]==1)&&
            (non[0]==1&&non[1]!=1&&non[2]==1))
            return -1;
            cout <<"//////";
             if((non[0]==non[1]&&non[2]==1)||
            (non[0]==1&&non[1]==non[2])||
            (non[0]==non[2]&&non[1]==1)
            )
            return -1;
        }
        // sort(frequencyMap.begin(),frequencyMap.end());
        // cout<<"freq"<<frequencyMap.size()<<endl;
        if(nonZero==1)
        return -1;

        // Find the number with the highest frequency
        int mostFrequent = vec[0];
        int maxCount = 0;
        for (const auto& pair : frequencyMap) {
            if(mostFrequent==1&&pair.first!=1)
            {
                mostFrequent = pair.first;
                maxCount = pair.second;
                continue;
            }
            if (pair.second >= maxCount) {
                mostFrequent = pair.first;
                maxCount = pair.second;
            }
        }
        // if(frequencyMap[mostFrequent]==1)
        // return -1;

        return mostFrequent;
    }

    bool equalFrequency(string word) {
        unordered_map<char, int> map;
        vector<int> freq_vec(26);
        for (int i = 0; i < word.length(); i++) {
            map[word[i]]++;
        }
        int k=0;
        for (int i=0;i<26&&k<word.length();i++) {
            int index=word[k]-'a';
            // cout<<index;
            freq_vec[index]=map[word[k]];
            k++;
        }
        sort(freq_vec.begin(),freq_vec.end());
        int freq = map[word[0]];
        int freq2;
        int freq3;
        if (word[0] != word[1])
            freq2 = map[word[1]];
        else if (word[0] != word[word.length() - 1])
            freq2 = map[word[word.length() - 1]];
        else
            freq2 = map[word[word.length() - 2]];

        if (freq2 < freq)
            freq = freq2;
        freq = mostFrequentNumber(freq_vec);
        if(freq==-1) return true;
        // cout << freq;
        bool removed = false;
        for (int i = 0; i < word.length(); i++) {
            int diff = abs(-freq + map[word[i]]);
            if (diff == 1) {
                removed = true;
                map[word[i]]--;
                if(map[word[i]]==0)return true;
                break;
            } else if ((diff > 1 || diff < 0)&&(freq!=1||map[word[i]]!=1)) {
                return false;
            }
        }
        if (!removed) {
            if (freq == 1)
                return true;
            else
                return false;
        }

        for (int i = 0; i < word.length(); i++) {
            int diff = (-freq + map[word[i]]);
            if (diff != 0) {
                return false;
            }
        }
        return true;
    }
};