class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros;

        // Step 1: Count trailing zeros for each row
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) count++;
                else break;
            }
            trailingZeros.push_back(count);
        }

        int totalSwaps = 0;

        // Step 2: Greedy swap to satisfy requirements
        for (int i = 0; i < n; i++) {
            int required = n - 1 - i;
            int foundIdx = -1;

            // Find the first row that satisfies the requirement
            for (int j = i; j < n; j++) {
                if (trailingZeros[j] >= required) {
                    foundIdx = j;
                    break;
                }
            }

            // If no row satisfies the condition, it's impossible
            if (foundIdx == -1) return -1;

            // Step 3: Bubble the row up to the current position i
            for (int k = foundIdx; k > i; k--) {
                swap(trailingZeros[k], trailingZeros[k - 1]);
                totalSwaps++;
            }
        }

        return totalSwaps;
    }
};