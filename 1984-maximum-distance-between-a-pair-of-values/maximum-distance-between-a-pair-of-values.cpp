class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int max_dist = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        while (i < n1 && j < n2) {
            // Check if the current pair is valid
            if (nums1[i] <= nums2[j]) {
                // If valid, calculate distance and try to increase j
                max_dist = max(max_dist, j - i);
                j++;
            } else {
                // If invalid, nums1[i] is too big, move i forward
                i++;
                // Optimization: Ensure j is at least at i to keep distance non-negative
                if (j < i) {
                    j = i;
                }
            }
        }

        return max_dist;
    }
};