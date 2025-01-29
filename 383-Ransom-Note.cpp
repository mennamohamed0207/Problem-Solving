class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mapRan;
        unordered_map<char, int> mapMag;
        for (char c : ransomNote) {
            mapRan[c]++;
        }
        for (char c : magazine) {
            mapMag[c]++;
        }
        for (auto pair : mapRan) {
            if (mapMag[pair.first] < pair.second)
                return false;
        }
        return true;
    }
};