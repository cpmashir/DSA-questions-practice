class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> sums;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // Every single cell is a rhombus of radius 0
                sums.insert(grid[r][c]);
                if (sums.size() > 3) sums.erase(sums.begin());

                // Try expanding the rhombus radius k
                for (int k = 1; ; ++k) {
                    // Check if the 4 corners are within bounds
                    if (r - k < 0 || r + k >= m || c - k < 0 || c + k >= n) break;

                    int currentSum = 0;
                    // Top to Right, Right to Bottom, Bottom to Left, Left to Top
                    // We sum the segments to form the border
                    for (int i = 0; i < k; ++i) {
                        currentSum += grid[r - k + i][c + i]; // Top to Right
                        currentSum += grid[r + i][c + k - i]; // Right to Bottom
                        currentSum += grid[r + k - i][c - i]; // Bottom to Left
                        currentSum += grid[r - i][c - k + i]; // Left to Top
                    }

                    sums.insert(currentSum);
                    if (sums.size() > 3) sums.erase(sums.begin());
                }
            }
        }

        // Convert set to vector and sort descending
        vector<int> result(sums.rbegin(), sums.rend());
        return result;
    }
};