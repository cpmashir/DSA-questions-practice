class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        static const int MOD = 1000000007;

        vector<int> pos, digit;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int n = digit.size();
        vector<long long> pow10(n + 1, 1), prefVal(n + 1, 0), prefSum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pow10[i + 1] = (pow10[i] * 10) % MOD;
            prefVal[i + 1] = (prefVal[i] * 10 + digit[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digit[i];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = lower_bound(pos.begin(), pos.end(), q[0]) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), q[1]) - pos.begin();

            if (l == r) {
                ans.push_back(0);
                continue;
            }

            int len = r - l;
            long long x = (prefVal[r] - prefVal[l] * pow10[len]) % MOD;
            if (x < 0) x += MOD;

            long long sum = prefSum[r] - prefSum[l];
            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};