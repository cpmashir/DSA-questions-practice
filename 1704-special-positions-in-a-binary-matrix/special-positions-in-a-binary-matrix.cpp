class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> rowCounts(m, 0);
        vector<int> colCounts(n, 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    rowCounts[i]++;
                    colCounts[j]++;
                }
            }
        }
        
        int specialPositions = 0;
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