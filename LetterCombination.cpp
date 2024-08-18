#include <map>
#include <vector>

class Solution {
public:
   
    vector<string> letterCombinations(string digits) {
        vector<string> result;
    map<int,string> phone_numbers;
    phone_numbers[2]="abc";
    phone_numbers[3]="def";
    phone_numbers[4]="ghi";
    phone_numbers[5]="jkl";
    phone_numbers[6]="mno";
    phone_numbers[7]="pqrs";
    phone_numbers[8]="tuv";
    phone_numbers[9]="wxyz";
    if(digits.length()==1)
    {
        for(int i=0;i<phone_numbers[digits[0]].length();i++)
        {
            result.push_back(phone_numbers[digits[0]][i]);

        }
    }
    return result;

    
    }
};