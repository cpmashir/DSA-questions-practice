class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<char>> best(m, vector<char>(n, -1));
        queue<pair<int, int>> q;

        int start = health - grid[0][0];
        if (start <= 0) return false;

        best[0][0] = start;
        q.push({0, 0});

        int d[5] = {-1, 0, 1, 0, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nx = x + d[k], ny = y + d[k + 1];
                if ((unsigned)nx >= m || (unsigned)ny >= n) continue;

                char rem = best[x][y] - grid[nx][ny];
                if (rem <= 0 || rem <= best[nx][ny]) continue;

                best[nx][ny] = rem;
                q.push({nx, ny});
            }
        }

        return false;
    }
};