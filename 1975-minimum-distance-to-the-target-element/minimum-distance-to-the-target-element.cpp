class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int min_dist = INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                // Calculate the absolute distance
                int current_dist = abs(i - start);
                
                // Update min_dist if the current one is smaller
                if (current_dist < min_dist) {
                    min_dist = current_dist;
                }
                
                // Optimization: If distance is 0, we can't do better
                if (min_dist == 0) return 0;
            }
        }
        
        return min_dist;
    }
};