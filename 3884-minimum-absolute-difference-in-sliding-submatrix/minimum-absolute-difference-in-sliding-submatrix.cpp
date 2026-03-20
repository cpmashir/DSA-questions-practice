#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        int resRows = m - k + 1;
        int resCols = n - k + 1;
        vector<vector<int>> ans(resRows, vector<int>(resCols));

        for (int i = 0; i < resRows; ++i) {
            for (int j = 0; j < resCols; ++j) {
                vector<int> elements;
                
                // Collect elements
                for (int r = i; r < i + k; ++r) {
                    for (int c = j; c < j + k; ++c) {
                        elements.push_back(grid[r][c]);
                    }
                }

                // Sort and remove duplicates to only consider "distinct values"
                sort(elements.begin(), elements.end());
                elements.erase(unique(elements.begin(), elements.end()), elements.end());

                // If there are fewer than 2 distinct values, the answer is 0
                if (elements.size() < 2) {
                    ans[i][j] = 0;
                    continue;
                }

                int minVal = INT_MAX;
                for (int x = 0; x < (int)elements.size() - 1; ++x) {
                    int diff = elements[x + 1] - elements[x];
                    if (diff < minVal) {
                        minVal = diff;
                    }
                }
                ans[i][j] = minVal;
            }
        }

        return ans;
    }
};