class Solution {
public:
    bool canJump(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int maxReachable = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (i > maxReachable) {
                return false;
            }
            
            maxReachable = max(maxReachable, i + nums[i]);
            
            if (maxReachable >= n - 1) {
                return true;
            }
        }
        
        return false;
    }
};