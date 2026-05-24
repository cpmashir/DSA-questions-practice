class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findBound(nums, target, true);
        // If the left bound doesn't exist, the target isn't in the array
        if (left == -1) {
            return {-1, -1};
        }
        int right = findBound(nums, target, false);
        return {left, right};
    }

private:
    int findBound(const vector<int>& nums, int target, bool isFirst) {
        int low = 0;
        int high = nums.size() - 1;
        int bound = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                bound = mid; // Record the current match
                if (isFirst) {
                    high = mid - 1; // Look left for the first occurrence
                } else {
                    low = mid + 1;  // Look right for the last occurrence
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return bound;
    }
};