class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2];
            long long v = q[3];
            
            if (v == 1) continue; 

            for (int i = l; i <= r; i += k) {
                nums[i] = (1LL * nums[i] * v) % MOD;
            }
        }

        int res = 0;
        for (int x : nums) res ^= x;
        return res;
    }
};