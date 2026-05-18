#pragma GCC optimize("Os") // Optimize the binary specifically for memory size
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_water = 0;
        
        // Use raw pointers to keep data entirely in CPU registers
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