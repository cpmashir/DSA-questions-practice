class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int freq[1501] = {};
        int max_f = 0;
        int min_p = budget + 1;

        for (const auto& item : items) {
            int f = item[0], p = item[1];
            freq[f]++;
            if (f > max_f) max_f = f;
            if (p < min_p) min_p = p;
        }

        if (min_p > budget) return 0;

        int mult[1501] = {};
        for (int f = 1; f <= max_f; ++f) {
            if (!freq[f]) continue;
            int cnt = 0;
            for (int m = f; m <= max_f; m += f) {
                cnt += freq[m];
            }
            mult[f] = cnt;
        }

        int dp[1501] = {};
        int limit = 0;
        for (const auto& item : items) {
            int p = item[1];
            if (p > budget) continue;
            int v = mult[item[0]];
            limit = min(budget, limit + p);
            for (int c = limit; c >= p; --c) {
                int cand = dp[c - p] + v;
                if (cand > dp[c]) dp[c] = cand;
            }
        }

        int ans = 0;
        for (int c = 0; c <= limit; ++c) {
            int cand = dp[c] + (budget - c) / min_p;
            if (cand > ans) ans = cand;
        }

        return ans;
    }
};