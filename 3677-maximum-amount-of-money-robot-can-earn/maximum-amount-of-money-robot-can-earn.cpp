#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        long long INF = 1e16;
        
        vector<vector<long long>> dp(n, vector<long long>(3, -INF));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    dp[0][0] = coins[0][0];
                    dp[0][1] = max(0, coins[0][0]);
                    dp[0][2] = max(0, coins[0][0]);
                    continue;
                }

                for (int k = 2; k >= 0; --k) {
                    long long stay = dp[j][k]; 
                    long long left = (j > 0) ? dp[j - 1][k] : -INF;
                    long long best_prev = max(stay, left);

                    long long res = -INF;
                    if (best_prev != -INF) {
                        res = best_prev + coins[i][j];
                    }

                    if (k > 0) {
                        long long stay_k = dp[j][k - 1];
                        long long left_k = (j > 0) ? dp[j - 1][k - 1] : -INF;
                        long long best_prev_k = max(stay_k, left_k);
                        
                        if (best_prev_k != -INF) {
                            res = max(res, best_prev_k + max(0, coins[i][j]));
                        }
                    }
                    dp[j][k] = res;
                }
            }
        }

        return (int)max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};