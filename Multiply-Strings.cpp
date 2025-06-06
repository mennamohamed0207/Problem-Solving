class Solution {
public:
   
    vector<int>intermediate_results(string num1,char digit,int numZeros)
    {
        vector<int>currentResult(numZeros,0);
        int carry=0;
        for(char num1_digit:num1)
        {
            int multiply=(digit-'0')*(num1_digit-'0')+carry;
            carry=multiply/10;
            currentResult.push_back(multiply % 10);
        }
        if(carry)
        {
            currentResult.push_back(carry);
        }
        return currentResult;
    }
    string sumIntermediateResults(vector<vector<int>>&results)
    {
        vector<int> answer =results.back();
        vector<int> newAnswer;
        results.pop_back();
        for (vector<int> result:results)
        {
            newAnswer.clear();
            int carry=0;
            for(int i=0;i<answer.size()||i<result.size();i++)
            {
                int digit1 = i < result.size() ? result[i] : 0;
                int digit2 = i < answer.size() ? answer[i] : 0;
                int sum= digit1+digit2+carry;
                carry=sum/10;
                newAnswer.push_back(sum%10);
            }
            if(carry)
            newAnswer.push_back(carry);

            answer=newAnswer;
        }
        string finalAnswer;
        for (int digit : answer) {
            finalAnswer.push_back(digit + '0');
        }
        return finalAnswer;
    }
    string multiply(string num1, string num2) {
        if(num1==\0\||num2==\0\)
        return \0\;
        //the regular multiply operation
        // 123*456=
        // 738
        //6150
       //49200
        reverse(num2.begin(),num2.end());
        reverse(num1.begin(),num1.end());
        vector<vector<int>> results;
        for(int i=0;i<num2.length();i++)
        {
            results.push_back(intermediate_results(num1,num2[i],i));
        }
        string answer=sumIntermediateResults(results);
        reverse(answer.begin(),answer.end());
        return answer;
    }
};