class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>rows;
        vector<int>cols;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.push_back(i);
                    cols.push_back(j);
                    
                }
            }
        }
        for(int i=0;i<rows.size();i++)
        {for(int j=0;j<matrix[0].size();j++)
            {
                matrix[rows[i]][j]=0;
            }
        }
        for(int i=0;i<cols.size();i++)
        {for(int j=0;j<matrix.size();j++)
            {
                matrix[j][cols[i]]=0;
            }
        }
    }
};