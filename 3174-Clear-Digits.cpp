class Solution {
public:
    string clearDigits(string s) {
        string result;
        
        for(char c : s) {
            if (!isdigit(c)) {
                result.push_back(c); // Append non-digit character
            } else if (!result.empty()) {
                result.pop_back(); // Remove last added character if result is not empty
            }
        }  
        return result;      
    }
};
