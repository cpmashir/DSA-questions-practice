class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int masks[7] = {0, 10, 5, 12, 6, 9, 3};
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            int r = curr.first, c = curr.second;
            q.pop();

            if (r == m - 1 && c == n - 1) return true;

            for (int i = 0; i < 4; ++i) {
                if (masks[grid[r][c]] & (1 << i)) {
                    int nr = r + dx[i], nc = c + dy[i];
                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        int backDir = (i + 2) % 4;
                        if (masks[grid[nr][nc]] & (1 << backDir)) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
        return false;
    }
};