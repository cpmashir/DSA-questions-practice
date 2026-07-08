class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;

        vector<int> idx, d;
        idx.reserve(s.size());
        d.reserve(s.size());

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '0') {
                idx.push_back(i);
                d.push_back(s[i] - '0');
            }
        }

        int n = d.size();
        vector<int> pw(n + 1), preVal(n + 1), preSum(n + 1);
        pw[0] = 1;

        for (int i = 0; i < n; ++i) {
            pw[i + 1] = (long long)pw[i] * 10 % MOD;
            preVal[i + 1] = ((long long)preVal[i] * 10 + d[i]) % MOD;
            preSum[i + 1] = preSum[i] + d[i];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = lower_bound(idx.begin(), idx.end(), q[0]) - idx.begin();
            int r = upper_bound(idx.begin(), idx.end(), q[1]) - idx.begin();

            if (l == r) {
                ans.push_back(0);
                continue;
            }

            int len = r - l;
            long long x = preVal[r] - (long long)preVal[l] * pw[len] % MOD;
            if (x < 0) x += MOD;

            ans.push_back(x * (preSum[r] - preSum[l]) % MOD);
        }

        return ans;
    }
};