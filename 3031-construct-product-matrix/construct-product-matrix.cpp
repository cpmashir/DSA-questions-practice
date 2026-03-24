#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;
        
        vector<vector<int>> p(n, vector<int>(m));
        long long runningProduct = 1;

        // Step 1: Calculate Prefix Products
        // p[i][j] will store the product of all elements before grid[i][j]
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[i][j] = runningProduct;
                runningProduct = (runningProduct * (grid[i][j] % MOD)) % MOD;
            }
        }

        runningProduct = 1;

        // Step 2: Calculate Suffix Products and combine
        // Multiply the current prefix product by the product of all elements after grid[i][j]
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                p[i][j] = (p[i][j] * runningProduct) % MOD;
                runningProduct = (runningProduct * (grid[i][j] % MOD)) % MOD;
            }
        }

        return p;
    }
};