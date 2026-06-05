class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Initialize an n x n matrix with 0
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        // Define the boundaries
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        
        int num = 1; // Start filling from 1
        int target = n * n;
        
        while (num <= target) {
            // 1. Move from left to right across the top row
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            top++; // Move the top boundary down
            
            // 2. Move from top to bottom down the right column
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--; // Move the right boundary left
            
            // 3. Move from right to left across the bottom row
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            bottom--; // Move the bottom boundary up
            
            // 4. Move from bottom to top up the left column
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++; // Move the left boundary right
        }
        
        return matrix;
    }
};