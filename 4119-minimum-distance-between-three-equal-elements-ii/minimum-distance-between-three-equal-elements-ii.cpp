class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> pos(n + 1);
        
        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }
        
        int min_dist = INT_MAX;
        bool found = false;
        
        for (int val = 1; val <= n; ++val) {
            if (pos[val].size() >= 3) {
                found = true;
                for (int m = 0; m <= (int)pos[val].size() - 3; ++m) {
                    int current_dist = 2 * (pos[val][m + 2] - pos[val][m]);
                    min_dist = min(min_dist, current_dist);
                }
            }
        }
        
        return found ? min_dist : -1;
    }
};