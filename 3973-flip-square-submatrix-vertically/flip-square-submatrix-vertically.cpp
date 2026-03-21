#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int top = x;
        int bottom = x + k - 1;

        // Perform the vertical flip by swapping rows within the submatrix
        while (top < bottom) {
            // Iterate through the columns within the submatrix's width k
            for (int j = y; j < y + k; ++j) {
                swap(grid[top][j], grid[bottom][j]);
            }
            
            // Move the row pointers toward the center
            top++;
            bottom--;
        }

        return grid;
    }
};