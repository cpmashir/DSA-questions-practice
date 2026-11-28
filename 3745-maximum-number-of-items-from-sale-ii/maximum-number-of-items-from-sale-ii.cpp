class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);
        long long mn = LLONG_MAX;

        for (auto &x : items) {
            freq[x[0]]++;
            mn = min(mn, (long long)x[1]);
        }

        vector<int> cnt(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i)
                cnt[i] += freq[j];
        }

        vector<pair<long long, long long>> v;

        for (auto &x : items) {
            long long p = x[1];
            long long c = cnt[x[0]] - 1;

            if (c > 0 && p < 2 * mn)
                v.push_back({p, c});
        }

        sort(v.begin(), v.end());

        long long spent = 0, bonus = 0;

        for (auto &[p, c] : v) {
            long long take = min(c, (budget - spent) / p);
            spent += take * p;
            bonus += take;
        }

        return 2 * bonus + (budget - spent) / mn;
    }
};