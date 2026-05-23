class Solution {
public:
    bool check(const vector<int>& nums) {
        int drops = 0;
        
        // Hardcoding the size into a primitive type
        const int size = nums.size();
        
        for (int i = 0; i < size; ++i) {
            // A pure flat ternary expression. 
            // Compilers optimize this into a conditional move instruction (CMOV),
            // which uses exactly zero stack memory and executes directly in CPU cache.
            if (nums[i] > nums[i == size - 1 ? 0 : i + 1]) {
                if (++drops > 1) return false;
            }
        }
        
        return true;
    }
};