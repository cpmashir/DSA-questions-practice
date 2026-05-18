// This static block forces the compiler to disable C/C++ I/O synchronization 
// before the LeetCode main runner even initializes the solution class.
auto speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        
        // Use raw pointers to keep data strictly inside CPU registers 
        // and eliminate stack frames.
        const int* left = height.data();
        const int* right = left + height.size() - 1;
        
        while (left < right) {
            int h_left = *left;
            int h_right = *right;
            
            int current_water = (right - left) * (h_left < h_right ? h_left : h_right);
            if (current_water > max_water) {
                max_water = current_water;
            }
            
            if (h_left < h_right) {
                while (left < right && *left <= h_left) left++;
            } else {
                while (left < right && *right <= h_right) right--;
            }
        }
        
        return max_water;
    }
};