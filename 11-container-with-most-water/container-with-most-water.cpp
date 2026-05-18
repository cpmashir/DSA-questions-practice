class Solution {
public:
    int maxArea(vector<int>& height) {
        // Optimize standard I/O operations for performance
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            int h_left = height[left];
            int h_right = height[right];
            
            // Calculate area using the shorter line
            int min_h = (h_left < h_right) ? h_left : h_right;
            int current_water = (right - left) * min_h;
            
            if (current_water > max_water) {
                max_water = current_water;
            }
            
            // Fast-forward past lines that are shorter or equal 
            // since they can never yield a larger area with a smaller width
            if (h_left < h_right) {
                while (left < right && height[left] <= h_left) {
                    left++;
                }
            } else {
                while (left < right && height[right] <= h_right) {
                    right--;
                }
            }
        }
        
        return max_water;
    }
};