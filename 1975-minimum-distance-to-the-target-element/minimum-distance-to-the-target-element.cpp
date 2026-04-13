class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int min_dist = INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                int current_dist = abs(i - start);
                if (current_dist < min_dist) {
                    min_dist = current_dist;
                }
                if (min_dist == 0) return 0;
            }
        }
        
        return min_dist;
    }
};