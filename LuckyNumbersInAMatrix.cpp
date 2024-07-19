/*Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 105.
All elements in the matrix are distinct.
*/
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int* min = new int[matrix.size()];
        int* max = new int[matrix[0].size()];
        for (int i = 0; i < matrix[0].size(); i++) {
            max[i] = 0;
        }
        int j = 0;
        for (int i = 0; i < matrix.size(); i++) {
            min[i] = *min_element(matrix[i].begin(), matrix[i].end());
            cout << "min"
                 << " ";

            cout << min[i] << endl;
           for (int j = 0; j < matrix[i].size(); j++)
            {
                if (max[j] < matrix[i][j]) {
                    max[j] = matrix[i][j];
                    cout << "max"
                         << " ";
                    cout << max[j] << endl;
                }
                   
           }
        }
        vector<int> result;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == min[i] && matrix[i][j] == max[j])
                    result.push_back(max[j]);
            }
        }
        return result;
    }
};

