class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // If the current index is beyond the maximum reachable index,
            // it means we can't even get to this point.
            if (i > maxReachable) {
                return false;
            }
            
            // Update the furthest index we can reach from the current position
            maxReachable = max(maxReachable, i + nums[i]);
            
            // Optimization: If we can already reach or exceed the last index, return true
            if (maxReachable >= n - 1) {
                return true;
            }
        }
        
        return false;
    }
};