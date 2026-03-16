class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto d1 = vector<vector<int>>(m + 1, vector<int>(n + 2, 0));
        auto d2 = vector<vector<int>>(m + 1, vector<int>(n + 2, 0));
        set<int> top3;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                d1[i + 1][j + 1] = grid[i][j] + d1[i][j];
                d2[i + 1][j + 1] = grid[i][j] + d2[i][j + 2];
                top3.insert(grid[i][j]);
                if (top3.size() > 3) top3.erase(top3.begin());
            }
        }

        for (int k = 1; k <= min(m, n) / 2; ++k) {
            for (int i = k; i < m - k; ++i) {
                for (int j = k; j < n - k; ++j) {
                    int top = i - k, bottom = i + k, left = j - k, right = j + k;
                    
                    int side1 = d2[i + 1][left + 1] - d2[top][j + 2]; 
                    int side2 = d1[bottom + 1][j + 1] - d1[i][left];
                    int side3 = d2[bottom + 1][j + 1] - d2[i][right + 2];
                    int side4 = d1[i + 1][right + 1] - d1[top][j];

                    int total = side1 + side2 + side3 + side4 - grid[top][j] - grid[bottom][j] - grid[i][left] - grid[i][right];
                    
                    top3.insert(total);
                    if (top3.size() > 3) top3.erase(top3.begin());
                }
            }
        }

        return vector<int>(top3.rbegin(), top3.rend());
    }
};