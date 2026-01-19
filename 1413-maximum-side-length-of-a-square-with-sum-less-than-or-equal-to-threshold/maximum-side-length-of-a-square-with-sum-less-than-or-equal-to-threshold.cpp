class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> P(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                P[i][j] = mat[i-1][j-1] + P[i-1][j] + P[i][j-1] - P[i-1][j-1];
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int k = ans + 1;
                if (i >= k && j >= k) {
                    int currentSum = P[i][j] - P[i-k][j] - P[i][j-k] + P[i-k][j-k];
                    if (currentSum <= threshold) {
                        ans = k;
                    }
                }
            }
        }
        
        return ans;
    }
};