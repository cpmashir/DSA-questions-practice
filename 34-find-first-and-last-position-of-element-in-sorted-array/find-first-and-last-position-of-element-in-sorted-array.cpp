class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = -1, right = -1;
        
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target) left = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (left == -1) return {-1, -1};
        
        low = left, high = n - 1; 
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target) right = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return {left, right};
    }
};