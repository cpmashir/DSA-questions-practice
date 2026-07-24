class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        bool dp[4][MAXX] = {};
        dp[0][0] = true;

        for (int v : nums) {
            for (int cnt = 2; cnt >= 0; cnt--) {
                for (int x = 0; x < MAXX; x++) {
                    if (!dp[cnt][x]) continue;

                    dp[cnt + 1][x ^ v] = true;

                    if (cnt + 2 <= 3)
                        dp[cnt + 2][x] = true;

                    if (cnt + 3 <= 3)
                        dp[cnt + 3][x ^ v] = true;
                }
            }
        }

        int ans = 0;
        for (int x = 0; x < MAXX; x++)
            ans += dp[3][x];

        return ans;
    }
};