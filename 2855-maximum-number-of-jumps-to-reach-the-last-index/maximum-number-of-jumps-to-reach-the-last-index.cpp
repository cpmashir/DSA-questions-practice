class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int j = 1; j < n; ++j) {
            int current_val = nums[j];
            for (int i = 0; i < j; ++i) {
                if (dp[i] != -1) {
                    long long diff = (long long)current_val - nums[i];
                    if (diff >= -target && diff <= target) {
                        if (dp[i] + 1 > dp[j]) {
                            dp[j] = dp[i] + 1;
                        }
                    }
                }
            }
        }
        return dp[n - 1];
    }
};