class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<char>> dist(m, vector<char>(n, 127));
        deque<pair<int, int>> dq;

        dist[0][0] = grid[0][0];
        dq.emplace_front(0, 0);

        static const int d[5] = {-1, 0, 1, 0, -1};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            char cur = dist[x][y];
            if (x == m - 1 && y == n - 1)
                return cur < health;

            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k], ny = y + d[k + 1];
                if ((unsigned)nx >= (unsigned)m || (unsigned)ny >= (unsigned)n)
                    continue;

                char nd = cur + grid[nx][ny];
                if (nd >= dist[nx][ny]) continue;

                dist[nx][ny] = nd;
                if (grid[nx][ny])
                    dq.emplace_back(nx, ny);
                else
                    dq.emplace_front(nx, ny);
            }
        }

        return false;
    }
};