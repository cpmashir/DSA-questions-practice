class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Use modulo (%) to cleanly wrap around from the last element to the first
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            
            // Optimization: If we see more than 1 drop, we can fail early
            if (count > 1) {
                return false;
            }
        }
        
        return true;
    }
};