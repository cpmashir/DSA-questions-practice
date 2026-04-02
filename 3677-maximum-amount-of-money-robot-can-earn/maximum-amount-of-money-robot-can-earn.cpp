#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // dp[i][j][k] represents max coins at (i, j) with k neutralizations used
        // Initialize with a very small number to represent unreached states
        long long INF = 1e15;
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, -INF)));

        // Base case: Starting point (0,0)
        dp[0][0][0] = coins[0][0]; // Don't neutralize (0,0)
        dp[0][0][1] = max(0, coins[0][0]); // Neutralize (0,0) if it's negative
        dp[0][0][2] = max(0, coins[0][0]); // Neutralize (0,0) (wasteful to use 2, but valid)

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k < 3; ++k) {
                    long long prev_max = -INF;
                    
                    // Coming from Up or Left
                    if (i > 0) prev_max = max(prev_max, dp[i - 1][j][k]);
                    if (j > 0) prev_max = max(prev_max, dp[i][j - 1][k]);

                    // Case 1: Don't neutralize current cell (i, j)
                    if (prev_max != -INF) {
                        dp[i][j][k] = max(dp[i][j][k], prev_max + coins[i][j]);
                    }

                    // Case 2: Use a neutralization on current cell (i, j)
                    if (k > 0) {
                        long long prev_k_minus_1 = -INF;
                        if (i > 0) prev_k_minus_1 = max(prev_k_minus_1, dp[i - 1][j][k - 1]);
                        if (j > 0) prev_k_minus_1 = max(prev_k_minus_1, dp[i][j - 1][k - 1]);
                        
                        if (prev_k_minus_1 != -INF) {
                            // If we neutralize a negative cell, treat it as 0
                            dp[i][j][k] = max(dp[i][j][k], prev_k_minus_1 + max(0, coins[i][j]));
                        }
                    }
                }
            }
        }

        // The answer is the maximum coins at the bottom-right using 0, 1, or 2 neutralizations
        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};