class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> nums;
        
        // 1. Flatten the grid into a 1D vector
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                nums.push_back(grid[i][j]);
            }
        }
        
        // 2. Check if it's possible: all elements must have same remainder mod x
        int remainder = nums[0] % x;
        for (int val : nums) {
            if (val % x != remainder) {
                return -1;
            }
        }
        
        // 3. Sort to find the median
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        
        // 4. Calculate total operations to reach the median
        int totalOps = 0;
        for (int val : nums) {
            totalOps += abs(val - median) / x;
        }
        
        return totalOps;
    }
};