class Solution {
public:
    bool check(const vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Micro-optimization: The modulo operator (%) can sometimes be slow. 
            // Hand-rolling the wrap-around keeps the assembly instructions minimal.
            int next_idx = (i == n - 1) ? 0 : i + 1;
            
            if (nums[i] > nums[next_idx]) {
                if (++count > 1) {
                    return false;
                }
            }
        }
        
        return true;
    }
};