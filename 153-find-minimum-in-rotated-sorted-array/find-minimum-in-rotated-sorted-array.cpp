class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If the middle element is greater than the rightmost element,
            // the minimum must be in the right part of the array.
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // Otherwise, the minimum is in the left part (including mid).
            else {
                right = mid;
            }
        }

        // When left == right, we've narrowed it down to the minimum element.
        return nums[left];
    }
};