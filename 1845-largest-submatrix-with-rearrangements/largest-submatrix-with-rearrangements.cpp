class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Step 1: Update heights based on the row above
                if (matrix[i][j] != 0 && i > 0) {
                    matrix[i][j] += matrix[i-1][j];
                }
            }

            // Step 2: Create a copy of the current row and sort it descending
            vector<int> currRow = matrix[i];
            sort(currRow.begin(), currRow.end(), greater<int>());

            // Step 3: Calculate potential area for each width
            for (int k = 0; k < n; k++) {
                maxArea = max(maxArea, currRow[k] * (k + 1));
            }
        }

        return maxArea;
    }
};