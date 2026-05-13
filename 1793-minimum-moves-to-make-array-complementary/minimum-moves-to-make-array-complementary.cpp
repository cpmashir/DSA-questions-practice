class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        // Difference array to track move changes for target sums from 2 to 2*limit
        // Size is 2*limit + 2 to handle index + 1 offsets safely
        vector<int> diff(2 * limit + 2, 0);
        int n = nums.size();
        
        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            
            // 1. Default: Assume 2 moves for every pair
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;
            
            // 2. Range for 1 move: [min(a,b)+1, max(a,b)+limit]
            // We subtract 1 move from the '2' we already added
            int left = min(a, b) + 1;
            int right = max(a, b) + limit;
            diff[left] -= 1;
            diff[right + 1] += 1;
            
            // 3. Range for 0 moves: exactly a + b
            // We subtract another 1 move from the '1' remaining
            int sum_ab = a + b;
            diff[sum_ab] -= 1;
            diff[sum_ab + 1] += 1;
        }
        
        int min_moves = n;
        int current_moves = 0;
        // Sweep from minimum possible sum (2) to maximum (2*limit)
        for (int i = 2; i <= 2 * limit; ++i) {
            current_moves += diff[i];
            if (current_moves < min_moves) {
                min_moves = current_moves;
            }
        }
        
        return min_moves;
    }
};