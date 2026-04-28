class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        int totalElements = m * n;
        vector<int> nums;
        nums.reserve(totalElements);

        int remainder = grid[0][0] % x;
        for (const auto& row : grid) {
            for (int val : row) {
                if (val % x != remainder) return -1;
                nums.push_back(val);
            }
        }

        auto median_it = nums.begin() + totalElements / 2;
        nth_element(nums.begin(), median_it, nums.end());
        int median = *median_it;

        int totalOps = 0;
        for (int val : nums) {
            totalOps += abs(val - median) / x;
        }

        return totalOps;
    }
};