class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> upLeft(m + 2, vector<int>(n + 2, 0));
        vector<vector<int>> upRight(m + 2, vector<int>(n + 2, 0));
        set<int> top3;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                upLeft[i + 1][j + 1] = grid[i][j] + upLeft[i][j];
                upRight[i + 1][j + 1] = grid[i][j] + upRight[i][j + 2];
                top3.insert(grid[i][j]);
                if (top3.size() > 3) top3.erase(top3.begin());
            }
        }

        for (int k = 1; k <= min(m, n) / 2; ++k) {
            for (int i = k; i < m - k; ++i) {
                for (int j = k; j < n - k; ++j) {
                    int rT = i - k, cT = j;
                    int rB = i + k, cB = j;
                    int rL = i, cL = j - k;
                    int rR = i, cR = j + k;

                    int s1 = upRight[rL + 1][cL + 1] - upRight[rT][cT + 2]; 
                    int s2 = upLeft[rB + 1][cB + 1] - upLeft[rL][cL];      
                    int s3 = upRight[rB + 1][cB + 1] - upRight[rR][cR + 2];
                    int s4 = upLeft[rR + 1][cR + 1] - upLeft[rT][cT];     

                    int total = s1 + s2 + s3 + s4 - grid[rT][cT] - grid[rB][cB] - grid[rL][cL] - grid[rR][cR];

                    top3.insert(total);
                    if (top3.size() > 3) top3.erase(top3.begin());
                }
            }
        }

        return vector<int>(top3.rbegin(), top3.rend());
    }
};