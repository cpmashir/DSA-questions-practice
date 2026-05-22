#include <vector>

// Ultimate fast I/O using C-style stream untying
static const auto __optimize_io__ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    // Using simple int types and standard inline conditions to avoid stack frames
    int search(std::vector<int>& nums, const int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            const int mid = low + (high - low) / 2;
            const int mid_val = nums[mid];
            
            if (mid_val == target) return mid;
            
            if (nums[low] <= mid_val) {
                if (target >= nums[low] && target < mid_val) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (target > mid_val && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};