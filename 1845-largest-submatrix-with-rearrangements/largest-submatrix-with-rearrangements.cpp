class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        
        // Use a single vector to store current heights to save memory
        vector<int> heights(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Update heights: if 1, increment; if 0, reset
                if (matrix[i][j] == 1) {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            // Copy heights to a temporary vector for sorting
            // Sorting is O(N log N), which is fine since N is the width
            vector<int> sortedHeights = heights;
            sort(sortedHeights.begin(), sortedHeights.end(), greater<int>());

            // Calculate max area for this row
            for (int k = 0; k < n; k++) {
                if (sortedHeights[k] == 0) break; // Optimization: no more 1s
                maxArea = max(maxArea, sortedHeights[k] * (k + 1));
            }
        }

        return maxArea;
    }
};