/*A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 

Example 1:


Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.
Example 2:

Input: grid = [[8]]
Output: 0
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15
*/
//Beats 57%
class Solution {
public:
    bool checkDistinct(vector<int> magic) {
        sort(magic.begin(), magic.end());
        for (int i = 0; i < magic.size(); i++) {
            cout << magic[i] << " ";
            if (i <= magic.size() - 2 && (magic[i] == magic[i + 1] ||
                                          (magic[i] <= 0 || magic[i] >= 10))) {
                return false;
            }
            if (i == magic.size() - 1 && (magic[i] <= 0 || magic[i] >= 10))
                return false;
        }
        cout << "sucess" << endl;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            int cols = grid[i].size();
            for (int j = 0; j < cols; j++) {
                int sum = 0;
                if (j <= cols - 3) {
                    sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                    if (i <= rows - 3&&grid[i][j]+grid[i+1][j]+grid[i+2][j]==sum) {
                        if (grid[i][j] + grid[i + 1][j + 1] +
                                grid[i + 2][j + 2] ==
                            sum) {
                            vector<int> magic;
                            magic.push_back(grid[i][j]);
                            magic.push_back(grid[i + 1][j]);
                            magic.push_back(grid[i + 2][j]);

                            magic.push_back(grid[i][j + 1]);
                            magic.push_back(grid[i + 1][j + 1]);
                            magic.push_back(grid[i + 2][j + 1]);

                            magic.push_back(grid[i][j + 2]);
                            magic.push_back(grid[i + 1][j + 2]);
                            magic.push_back(grid[i + 2][j + 2]);

                            if (checkDistinct(magic))
                                result++;
                        }
                    }
                }
            }
        }
        return result;
    }
};