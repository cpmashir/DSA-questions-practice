class Solution {
    int masks[7] = {0, 10, 5, 12, 6, 9, 3};
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool visited[300][300];
    pair<int, int> q[90005];

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return true;

        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                visited[i][j] = false;

        int head = 0, tail = 0;
        q[tail++] = {0, 0};
        visited[0][0] = true;

        while (head < tail) {
            pair<int, int> curr = q[head++];
            int r = curr.first, c = curr.second;

            if (r == m - 1 && c == n - 1) return true;

            int currentMask = masks[grid[r][c]];
            for (int i = 0; i < 4; ++i) {
                if (currentMask & (1 << i)) {
                    int nr = r + dx[i], nc = c + dy[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        if (masks[grid[nr][nc]] & (1 << ((i + 2) % 4))) {
                            visited[nr][nc] = true;
                            q[tail++] = {nr, nc};
                        }
                    }
                }
            }
        }
        return false;
    }
};