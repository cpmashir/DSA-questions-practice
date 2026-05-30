class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 1D DP array initialized to 1 
        // (Since there is only 1 way to reach any cell in the first row)
        vector<int> dp(n, 1);
        
        // Loop through the rest of the rows
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // dp[j] (current row) = dp[j] (from previous row) + dp[j-1] (from left neighbor)
                dp[j] += dp[j - 1];
            }
        }
        
        return dp[n - 1];
    }
};