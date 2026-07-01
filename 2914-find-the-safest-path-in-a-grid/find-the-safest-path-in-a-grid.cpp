class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        static const int d[5] = {-1, 0, 1, 0, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + d[k], ny = y + d[k + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    dist[nx][ny] == INT_MAX) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        priority_queue<array<int, 3>> pq;
        vector<vector<int>> best(n, vector<int>(n, -1));

        pq.push({dist[0][0], 0, 0});
        best[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int safe = cur[0], x = cur[1], y = cur[2];

            if (x == n - 1 && y == n - 1)
                return safe;

            if (safe != best[x][y])
                continue;

            for (int k = 0; k < 4; k++) {
                int nx = x + d[k], ny = y + d[k + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int ns = min(safe, dist[nx][ny]);
                    if (ns > best[nx][ny]) {
                        best[nx][ny] = ns;
                        pq.push({ns, nx, ny});
                    }
                }
            }
        }

        return 0;
    }
};