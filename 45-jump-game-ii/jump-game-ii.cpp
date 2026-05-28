class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0; // Already at the end

        int jumps = 0;
        int current_end = 0;
        int furthest = 0;

        // We don't need to process the last element because once we reach 
        // or can overshoot it, we stop.
        for (int i = 0; i < n - 1; ++i) {
            // Update the furthest we can reach from the current position
            furthest = max(furthest, i + nums[i]);

            // If we've reached the end of the range for the current jump
            if (i == current_end) {
                jumps++;             // We must jump
                current_end = furthest; // Update the boundary for the next jump
                
                // Optimization: If the next boundary already reaches or exceeds the last index
                if (current_end >= n - 1) {
                    break;
                }
            }
        }

        return jumps;
    }
};