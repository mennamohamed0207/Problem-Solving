class Solution {
public:
    bool isCircularSentence(string sentence) {
        int numberOfWords=0;
        for(int i=0;i<sentence.length();i++)
        {
            numberOfWords++;
            if(sentence[i]==' ')
            {
                if(sentence[i-1]!=sentence[i+1])
                return false;
            }
        }
        if(numberOfWords>0&&sentence[0]!=sentence[sentence.length()-1])
        return false;
        return true;
    }
};