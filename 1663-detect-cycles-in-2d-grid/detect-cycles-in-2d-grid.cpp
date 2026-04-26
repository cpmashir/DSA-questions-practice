class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> parent(m * n);
        iota(parent.begin(), parent.end(), 0);

        auto find = [&](auto& self, int i) -> int {
            return parent[i] == i ? i : parent[i] = self(self, parent[i]);
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0 && grid[i][j] == grid[i - 1][j]) {
                    int rootA = find(find, i * n + j);
                    int rootB = find(find, (i - 1) * n + j);
                    if (rootA == rootB) return true;
                    parent[rootA] = rootB;
                }
                if (j > 0 && grid[i][j] == grid[i][j - 1]) {
                    int rootA = find(find, i * n + j);
                    int rootB = find(find, i * n + (j - 1));
                    if (rootA == rootB) return true;
                    parent[rootA] = rootB;
                }
            }
        }
        return false;
    }
};