class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;

        int m = s.size();
        vector<int> rank(m + 1);
        vector<int> digit;
        digit.reserve(m);

        for (int i = 0; i < m; ++i) {
            rank[i] = digit.size();
            if (s[i] != '0')
                digit.push_back(s[i] - '0');
        }
        rank[m] = digit.size();

        int n = digit.size();

        vector<int> pw(n + 1, 1), val(n + 1), sum(n + 1);

        for (int i = 0; i < n; ++i) {
            pw[i + 1] = (long long)pw[i] * 10 % MOD;
            val[i + 1] = ((long long)val[i] * 10 + digit[i]) % MOD;
            sum[i + 1] = sum[i] + digit[i];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int L = rank[q[0]];
            int R = rank[q[1] + 1];

            if (L == R) {
                ans.push_back(0);
                continue;
            }

            long long x = val[R] - (long long)val[L] * pw[R - L] % MOD;
            if (x < 0) x += MOD;

            ans.push_back(x * (sum[R] - sum[L]) % MOD);
        }

        return ans;
    }
};