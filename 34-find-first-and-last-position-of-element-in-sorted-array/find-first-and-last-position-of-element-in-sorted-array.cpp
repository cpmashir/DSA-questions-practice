class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = -1, right = -1;
        
        // 1. Find Left Bound
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target) left = mid;
                high = mid - 1; // Force search to the left side
            } else {
                low = mid + 1;
            }
        }
        
        // If target wasn't found in the first pass, it's not in the array
        if (left == -1) return {-1, -1};
        
        // 2. Find Right Bound (Reuse variables to save stack memory)
        low = left, high = n - 1; 
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target) right = mid;
                low = mid + 1; // Force search to the right side
            } else {
                high = mid - 1;
            }
        }
        
        return {left, right};
    }
};