#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int totalElements = n * m;
        int MOD = 12345;
        
        vector<vector<int>> p(n, vector<int>(m));
        int runningProduct = 1;

        // Forward Pass: Calculate Prefix Products
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[i][j] = runningProduct;
                // Pre-calculate grid value modulo 12345
                int val = grid[i][j] % MOD;
                runningProduct = (runningProduct * val) % MOD;
            }
        }

        runningProduct = 1;

        // Backward Pass: Multiply by Suffix Products
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                // p[i][j] currently holds the prefix product
                p[i][j] = (p[i][j] * runningProduct) % MOD;
                int val = grid[i][j] % MOD;
                runningProduct = (runningProduct * val) % MOD;
            }
        }

        return p;
    }
};