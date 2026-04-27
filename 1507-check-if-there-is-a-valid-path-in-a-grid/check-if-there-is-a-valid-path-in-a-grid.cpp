#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // moves[street_type] defines the allowed directions of travel.
        // directions: 0: up, 1: right, 2: down, 3: left
        vector<vector<int>> moves = {
            {},             // 0: Padding
            {1, 3},         // 1: left <-> right
            {0, 2},         // 2: upper <-> lower
            {2, 3},         // 3: left <-> lower
            {1, 2},         // 4: right <-> lower
            {0, 3},         // 5: left <-> upper
            {0, 1}          // 6: right <-> upper
        };

        // Offset values for navigation: {up, right, down, left}
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            int r = curr.first;
            int c = curr.second;
            q.pop();

            // Check if we've reached the destination
            if (r == m - 1 && c == n - 1) return true;

            int street = grid[r][c];
            
            // Explore allowed directions for the current street type
            for (int dir : moves[street]) {
                int nr = r + dx[dir];
                int nc = c + dy[dir];

                // 1. Check grid boundaries
                // 2. Check if the cell was already visited
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int nextStreet = grid[nr][nc];
                    
                    // The 'backDir' is the direction pointing back to the current cell.
                    // If moving right (1), we check if the next cell has a left opening (3).
                    // Calculation: (dir + 2) % 4 effectively flips the direction.
                    int backDir = (dir + 2) % 4; 

                    bool connectsBack = false;
                    for (int nDir : moves[nextStreet]) {
                        if (nDir == backDir) {
                            connectsBack = true;
                            break;
                        }
                    }

                    if (connectsBack) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return false;
    }
};