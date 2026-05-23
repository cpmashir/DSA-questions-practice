class Solution {
public:
    bool check(vector<int> nums) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Eliminating variable allocations completely
            if (nums[i] > nums[(i + 1) % nums.size()]) {
                if (++count > 1) {
                    return false;
                }
            }
        }
        
        return true;
    }
};