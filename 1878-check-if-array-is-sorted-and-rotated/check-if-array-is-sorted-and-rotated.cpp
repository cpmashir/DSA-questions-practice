class Solution {
public:
    bool check(const vector<int>& nums) {
        int drops = 0;
        const int size = nums.size();
        
        for (int i = 0; i < size; ++i) {
            if (nums[i] > nums[i == size - 1 ? 0 : i + 1]) {
                if (++drops > 1) return false;
            }
        }
        
        return true;
    }
};