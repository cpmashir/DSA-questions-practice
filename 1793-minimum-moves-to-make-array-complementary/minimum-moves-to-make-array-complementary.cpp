#include <vector>
#include <algorithm>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        // We only need 2 * limit + 2 slots. 
        // Using a vector is fine, but we can pre-allocate.
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            // For each pair, we determine the ranges of target sum S:
            // 2 moves: [2, min(a, b)]
            // 1 move:  [min(a, b) + 1, a + b - 1]
            // 0 moves: a + b
            // 1 move:  [a + b + 1, max(a, b) + limit]
            // 2 moves: [max(a, b) + limit + 1, 2 * limit]

            // Optimized update:
            // Start by assuming 2 moves for everything:
            diff[2] += 2;
            
            // Discount 1 move for the [min+1, max+limit] range:
            int low = min(a, b) + 1;
            int high = max(a, b) + limit;
            diff[low] -= 1;
            diff[high + 1] += 1;
            
            // Discount another 1 move for the exact sum:
            int target = a + b;
            diff[target] -= 1;
            diff[target + 1] += 1;
        }

        int min_moves = n; 
        int current_moves = 0;
        
        // Linear sweep to find the minimum point in the prefix sum array
        for (int i = 2; i <= 2 * limit; ++i) {
            current_moves += diff[i];
            if (current_moves < min_moves) {
                min_moves = current_moves;
            }
        }

        return min_moves;
    }
};