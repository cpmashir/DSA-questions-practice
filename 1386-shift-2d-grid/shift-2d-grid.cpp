class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int total = m * n;
        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int idx = 0; idx < total; idx++) {
            int newIdx = (idx + k) % total;
            ans[newIdx / n][newIdx % n] = grid[idx / n][idx % n];
        }

        return ans;
    }
};