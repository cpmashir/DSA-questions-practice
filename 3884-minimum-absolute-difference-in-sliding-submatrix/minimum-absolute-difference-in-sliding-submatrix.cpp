#include <vector>
#include <set>
#include <algorithm>
#include <climits>

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
                // Use a set to keep elements sorted and handle "distinct" naturally
                // std::set automatically handles duplicates (we only store unique values)
                set<int> distinctElements;
                for (int r = i; r < i + k; ++r) {
                    for (int c = j; c < j + k; ++c) {
                        distinctElements.insert(grid[r][c]);
                    }
                }

                if (distinctElements.size() < 2) {
                    ans[i][j] = 0;
                    continue;
                }

                int minVal = INT_MAX;
                auto it = distinctElements.begin();
                int prev = *it;
                ++it;

                // Single pass through the sorted set
                for (; it != distinctElements.end(); ++it) {
                    int current = *it;
                    int diff = current - prev;
                    if (diff < minVal) {
                        minVal = diff;
                        if (minVal == 1) break; // Optimization: can't get smaller than 1 for distinct ints
                    }
                    prev = current;
                }
                ans[i][j] = minVal;
            }
        }
        return ans;
    }
};