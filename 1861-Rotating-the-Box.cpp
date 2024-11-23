class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        
        // Create the rotated box with dimensions m x n
        vector<vector<char>> rotatedBox(m, vector<char>(n, '.'));
        
        // Step 1: Simulate the falling of stones in the original box
        for (int i = 0; i < n; i++) {
            int empty = m - 1; // Start from the rightmost position
            for (int j = m - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    empty = j - 1; // Reset empty pointer before the obstacle
                } else if (box[i][j] == '#') {
                    box[i][j] = '.'; // Remove stone from the current position
                    box[i][empty] = '#'; // Place stone in the empty position
                    empty--; // Move empty pointer to the left
                }
            }
        }
        
        // Step 2: Rotate the box 90 degrees clockwise
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rotatedBox[j][n - 1 - i] = box[i][j];
            }
        }
        
        return rotatedBox;
    }
};
