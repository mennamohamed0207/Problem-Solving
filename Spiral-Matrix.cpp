class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix[0].size();
        int n=matrix.size();
        vector<int> result;
        int begin=0;
        do{
        for(int i=begin;i<m;i++)
        {
            result.push_back(matrix[begin][i]);
        }
        if(result.size()==matrix.size()*matrix[0].size())
        break;
        if(n==1) return result;
         for(int i=begin+1;i<n;i++)
        {
            result.push_back(matrix[i][m-1]);
        }
     if(result.size()==matrix.size()*matrix[0].size())
        break;
         for(int i=m-2;i>=begin;i--)
        {
            result.push_back(matrix[n-1][i]);
        }
         if(result.size()==matrix.size()*matrix[0].size())
        break;
         for(int i=n-2;i>begin;i--)
        {
            result.push_back(matrix[i][begin]);
        }
        m--;
        n--;
        begin++;
        }while(result.size() != matrix.size()*matrix[0].size());
        return result;

    }
};