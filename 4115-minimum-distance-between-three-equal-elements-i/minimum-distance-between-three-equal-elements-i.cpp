class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> positions[101];
        
        for (int i = 0; i < n; ++i) {
            positions[nums[i]].push_back(i);
        }
        
        int min_dist = INT_MAX;
        bool found = false;
        
        for (int v = 1; v <= 100; ++v) {
            if (positions[v].size() >= 3) {
                found = true;
                for (int p = 0; p <= (int)positions[v].size() - 3; ++p) {
                    int i = positions[v][p];
                    int k = positions[v][p + 2];
                    int current_dist = 2 * (k - i);
                    min_dist = min(min_dist, current_dist);
                }
            }
        }
        
        return found ? min_dist : -1;
    }
};