/*

*/


class Solution {
public:
    int minimumDeletions(string s) {
       vector<int>countB(s.length(),0);
       vector<int>countA(s.length(),0);
       int sumB=0;
       for(int i=0;i<s.length();i++)
       {
        countB[i]=sumB;
        if(s[i]=='b') sumB++;
       }
       int sumA=0;
       for(int i=s.length()-1;i>=0;i--)
       {
        countA[i]=sumA;
        if(s[i]=='a') sumA++;
       }
       int result=s.length();
       for(int i=0;i<s.length();i++)
       {
       result=min(result,countB[i]+countA[i]);
       }
       return result;
    }
};