class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        curr.reserve(k);

        long long total = 1;
        for (int i = 1; i <= k; i++)
            total = total * (n - i + 1) / i;

        ans.reserve(total);

        auto backtrack = [&](auto&& self, int start) -> void {
            if (curr.size() == k) {
                ans.push_back(curr);
                return;
            }

            int need = k - curr.size();

            for (int i = start; i <= n - need + 1; i++) {
                curr.push_back(i);
                self(self, i + 1);
                curr.pop_back();
            }
        };

        backtrack(backtrack, 1);
        return ans;
    }
};