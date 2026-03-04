class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Vectors to store the count of 1s in each row and column
        vector<int> rowCounts(m, 0);
        vector<int> colCounts(n, 0);
        
        // First pass: Populate the count arrays
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    rowCounts[i]++;
                    colCounts[j]++;
                }
            }
        }
        
        int specialPositions = 0;
        
        // Second pass: Check if the '1' is the only one in its row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && rowCounts[i] == 1 && colCounts[j] == 1) {
                    specialPositions++;
                }
            }
        }
        
        return specialPositions;
    }
};