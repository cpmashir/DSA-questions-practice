class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1), cnt(n + 1);

        long long mn = LLONG_MAX;

        for (auto &x : items) {
            freq[x[0]]++;
            mn = min(mn, (long long)x[1]);
        }

        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j += i)
                cnt[i] += freq[j];

        vector<pair<int, int>> v;

        for (auto &x : items) {
            if (cnt[x[0]] > 1 && x[1] < 2 * mn)
                v.push_back({x[1], cnt[x[0]] - 1});
        }

        sort(v.begin(), v.end());

        long long ans = 0;

        for (auto &[p, c] : v) {
            long long take = min((long long)c, (long long)budget / p);
            ans += 2 * take;
            budget -= take * p;
        }

        return ans + budget / mn;
    }
};