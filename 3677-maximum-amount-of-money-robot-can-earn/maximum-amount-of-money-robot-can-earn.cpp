#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        long long INF = 1e16;
        
        vector<vector<long long>> prev(n, vector<long long>(3, -INF));

        for (int i = 0; i < m; ++i) {
            vector<vector<long long>> curr(n, vector<long long>(3, -INF));
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (i == 0 && j == 0) {
                        curr[0][0] = coins[0][0];
                        curr[0][1] = max(0, coins[0][0]);
                        curr[0][2] = max(0, coins[0][0]);
                        break;
                    }

                    long long best_prev = -INF;
                    if (i > 0) best_prev = max(best_prev, prev[j][k]);
                    if (j > 0) best_prev = max(best_prev, curr[j - 1][k]);

                    if (best_prev != -INF) {
                        curr[j][k] = max(curr[j][k], best_prev + coins[i][j]);
                    }

                    if (k > 0) {
                        long long best_prev_k = -INF;
                        if (i > 0) best_prev_k = max(best_prev_k, prev[j][k - 1]);
                        if (j > 0) best_prev_k = max(best_prev_k, curr[j - 1][k - 1]);
                        
                        if (best_prev_k != -INF) {
                            curr[j][k] = max(curr[j][k], best_prev_k + max(0, coins[i][j]));
                        }
                    }
                }
            }
            prev = move(curr);
        }

        return max({prev[n - 1][0], prev[n - 1][1], prev[n - 1][2]});
    }
};