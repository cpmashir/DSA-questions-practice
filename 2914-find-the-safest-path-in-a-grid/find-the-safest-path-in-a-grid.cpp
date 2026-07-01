class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), N = n * n;
        vector<int> dist(N, INT_MAX);
        queue<int> q;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) {
                    int id = i * n + j;
                    dist[id] = 0;
                    q.emplace(id);
                }

        static const int dr[] = {-1, 1, 0, 0};
        static const int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int id = q.front();
            q.pop();
            int r = id / n, c = id % n;

            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if ((unsigned)nr < n && (unsigned)nc < n) {
                    int nid = nr * n + nc;
                    if (dist[nid] == INT_MAX) {
                        dist[nid] = dist[id] + 1;
                        q.emplace(nid);
                    }
                }
            }
        }

        priority_queue<pair<int, int>> pq;
        vector<char> vis(N, 0);

        pq.emplace(dist[0], 0);

        while (!pq.empty()) {
            auto [safe, id] = pq.top();
            pq.pop();

            if (vis[id]) continue;
            vis[id] = 1;

            if (id == N - 1) return safe;

            int r = id / n, c = id % n;

            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if ((unsigned)nr < n && (unsigned)nc < n) {
                    int nid = nr * n + nc;
                    if (!vis[nid])
                        pq.emplace(min(safe, dist[nid]), nid);
                }
            }
        }

        return 0;
    }
};