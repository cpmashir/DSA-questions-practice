auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;
        int n = nums.size();

        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2];
            long long v = q[3];

            if (v == 1) continue;

            int i = l;
            // Manual loop unrolling can sometimes help, 
            // but for k-steps, a tight pointer-based loop is best.
            int* ptr = nums.data();
            while (i <= r) {
                ptr[i] = (ptr[i] * v) % MOD;
                i += k;
            }
        }

        int res = 0;
        for (int x : nums) res ^= x;
        return res;
    }
};