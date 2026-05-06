class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Step 1: Simulate gravity for each row
        for (int i = 0; i < m; ++i) {
            int emptySlot = n - 1; // Start from the rightmost cell
            for (int j = n - 1; j >= 0; --j) {
                if (boxGrid[i][j] == '*') {
                    // Obstacle: stones cannot pass, reset empty slot to the left
                    emptySlot = j - 1;
                } else if (boxGrid[i][j] == '#') {
                    // Stone: move it to the furthest available empty slot
                    boxGrid[i][j] = '.';
                    boxGrid[i][emptySlot] = '#';
                    emptySlot--;
                }
            }
        }

        // Step 2: Rotate the grid 90 degrees clockwise
        // Original (m x n) -> Result (n x m)
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotatedBox[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return rotatedBox;
    }
};