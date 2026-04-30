class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        dp[0][0] = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                int score = (val == 2) ? 2 : (val == 1 ? 1 : 0);
                int cost = (val > 0) ? 1 : 0;

                for (int c = k; c >= 0; --c) {
                    if (i == 0 && j == 0) continue;

                    int res = -1;
                    if (i > 0 && c >= cost) {
                        res = max(res, dp[j][c - cost]);
                    }
                    if (j > 0 && c >= cost) {
                        res = max(res, dp[j - 1][c - cost]);
                    }

                    dp[j][c] = (res != -1) ? res + score : -1;
                }
            }
        }

        int maxScore = -1;
        for (int c = 0; c <= k; ++c) {
            maxScore = max(maxScore, dp[n - 1][c]);
        }

        return maxScore;
    }
};