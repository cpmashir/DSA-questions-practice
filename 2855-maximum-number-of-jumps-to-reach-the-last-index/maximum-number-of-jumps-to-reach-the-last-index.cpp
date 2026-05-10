class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        int dp[1000];
        fill(dp, dp + n, -1);
        dp[0] = 0;

        const int* data = nums.data();

        for (int j = 1; j < n; ++j) {
            int target_val = data[j];
            int max_j = -1;
            
            for (int i = 0; i < j; ++i) {
                if (dp[i] != -1) {
                    long long diff = (long long)target_val - data[i];
                    if (diff >= -target && diff <= target) {
                        if (dp[i] + 1 > max_j) {
                            max_j = dp[i] + 1;
                        }
                    }
                }
            }
            dp[j] = max_j;
        }
        return dp[n - 1];
    }
};