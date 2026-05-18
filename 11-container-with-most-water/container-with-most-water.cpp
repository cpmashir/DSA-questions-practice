class Solution {
public:
    int maxArea(vector<int>& height) {
        // Drastically cuts I/O memory buffer overhead
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int max_water = 0;
        
        // Using raw pointers instead of vector iterators/indexing 
        // removes standard vector bounds-checking overhead
        const int* left = &height[0];
        const int* right = &height[height.size() - 1];
        
        while (left < right) {
            int h_left = *left;
            int h_right = *right;
            
            // Calculate width using pointer arithmetic
            int width = right - left;
            int min_h = (h_left < h_right) ? h_left : h_right;
            int current_water = width * min_h;
            
            if (current_water > max_water) {
                max_water = current_water;
            }
            
            // Fast-forward pointers
            if (h_left < h_right) {
                while (left < right && *left <= h_left) {
                    left++;
                }
            } else {
                while (left < right && *right <= h_right) {
                    right--;
                }
            }
        }
        
        return max_water;
    }
};