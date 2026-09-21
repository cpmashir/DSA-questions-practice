class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0), dp(k, 0);

        for (int num : nums) {
            vector<long long> ndp(k, 0);
            int x = num % k;

            // Start a new subarray with nums[i]
            ndp[x]++;

            // Extend all subarrays ending at previous index
            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    ndp[(r * x) % k] += dp[r];
                }
            }

            dp = ndp;

            // Every subarray ending here contributes to the answer
            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};