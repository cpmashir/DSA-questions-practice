class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // Using short saves 50% memory compared to int for the DP table
        // -1 indicates unreachable
        short dp[1000]; 
        fill(dp, dp + n, -1);
        dp[0] = 0;

        for (int j = 1; j < n; ++j) {
            const int curr = nums[j];
            for (int i = 0; i < j; ++i) {
                if (dp[i] != -1) {
                    long long diff = (long long)curr - nums[i];
                    if (diff >= -target && diff <= target) {
                        if (dp[i] + 1 > dp[j]) {
                            dp[j] = dp[i] + 1;
                        }
                    }
                }
            }
        }
        return (int)dp[n - 1];
    }
};