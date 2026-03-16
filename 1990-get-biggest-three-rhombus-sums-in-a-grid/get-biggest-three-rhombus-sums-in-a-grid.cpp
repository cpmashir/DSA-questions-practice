#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> upLeft(m + 1, vector<int>(n + 2, 0));
        vector<vector<int>> upRight(m + 1, vector<int>(n + 2, 0));
        set<int> top3;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                upLeft[i + 1][j + 1] = grid[i][j] + upLeft[i][j];
                upRight[i + 1][j + 1] = grid[i][j] + upRight[i][j + 2];
                
                top3.insert(grid[i][j]);
                if (top3.size() > 3) top3.erase(top3.begin());
            }
        }

        for (int k = 1; k <= min(m, n) / 2; ++k) {
            for (int i = k; i < m - k; ++i) {
                for (int j = k; j < n - k; ++j) {
                    int topR = i - k, topC = j;
                    int botR = i + k, botC = j;
                    int lR = i, lC = j - k;
                    int rR = i, rC = j + k;

                    // Sum 4 edges using prefix sums
                    int s1 = upRight[lR + 1][lC + 1] - upRight[topR][topC + 2]; 
                    int s2 = upLeft[botR + 1][botC + 1] - upLeft[lR][lC];      
                    int s3 = upRight[botR + 1][botC + 1] - upRight[rR][rC + 2];
                    int s4 = upLeft[rR + 1][rC + 1] - upLeft[topR][topC];     

                    // Subtract the 4 corners because each was added twice
                    int total = s1 + s2 + s3 + s4 - grid[topR][topC] - grid[botR][botC] - grid[lR][lC] - grid[rR][rC];

                    top3.insert(total);
                    if (top3.size() > 3) top3.erase(top3.begin());
                }
            }
        }

        return vector<int>(top3.rbegin(), top3.rend());
    }
};