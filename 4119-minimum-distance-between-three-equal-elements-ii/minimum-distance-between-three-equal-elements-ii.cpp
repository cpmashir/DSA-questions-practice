class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        // Since nums[i] <= n, we can use a vector of vectors for O(1) access
        vector<vector<int>> pos(n + 1);
        
        // Step 1: Collect all indices for each unique value
        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }
        
        int min_dist = INT_MAX;
        bool found = false;
        
        // Step 2: Check each value's index list
        for (int val = 1; val <= n; ++val) {
            if (pos[val].size() >= 3) {
                found = true;
                // Sliding window of size 3 over the indices
                for (int m = 0; m <= (int)pos[val].size() - 3; ++m) {
                    // Distance formula simplified: 2 * (k - i)
                    int current_dist = 2 * (pos[val][m + 2] - pos[val][m]);
                    min_dist = min(min_dist, current_dist);
                }
            }
        }
        
        return found ? min_dist : -1;
    }
};