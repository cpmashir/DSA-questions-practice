#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j][c] stores the max score at (i, j) with cost c
        // Initialize with -1 to indicate unreachable states
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        // Base case: starting cell (0, 0)
        // grid[0][0] is guaranteed to be 0 per constraints, so cost 0, score 0
        dp[0][0][0] = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                int cellScore = (val == 2) ? 2 : (val == 1 ? 1 : 0);
                int cellCost = (val == 1 || val == 2) ? 1 : 0;

                for (int c = 0; c <= k; ++c) {
                    // Only proceed if this state was reachable from a previous cell
                    // Note: (0,0) is handled by the loop but we skip the "from" logic for it
                    if (i == 0 && j == 0) continue;

                    int prevMaxScore = -1;

                    // From Above
                    if (i > 0 && c >= cellCost) {
                        prevMaxScore = max(prevMaxScore, dp[i - 1][j][c - cellCost]);
                    }
                    // From Left
                    if (j > 0 && c >= cellCost) {
                        prevMaxScore = max(prevMaxScore, dp[i][j - 1][c - cellCost]);
                    }

                    if (prevMaxScore != -1) {
                        dp[i][j][c] = prevMaxScore + cellScore;
                    }
                }
            }
        }

        int maxScore = -1;
        for (int c = 0; c <= k; ++c) {
            maxScore = max(maxScore, dp[m - 1][n - 1][c]);
        }

        return maxScore;
    }
};