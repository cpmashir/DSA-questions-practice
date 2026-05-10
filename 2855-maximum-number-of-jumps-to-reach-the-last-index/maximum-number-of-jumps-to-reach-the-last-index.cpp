class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        short dp[1000];
        for (int i = 0; i < n; ++i) dp[i] = -1;
        dp[0] = 0;

        for (int j = 1; j < n; ++j) {
            const int val_j = nums[j];
            for (int i = 0; i < j; ++i) {
                if (dp[i] != -1) {
                    long long diff = (long long)val_j - nums[i];
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