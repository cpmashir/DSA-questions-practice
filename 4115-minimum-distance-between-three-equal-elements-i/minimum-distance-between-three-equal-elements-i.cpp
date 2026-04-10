class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        // Since nums[i] <= 100, we can use an array of vectors to store indices
        vector<int> positions[101];
        
        for (int i = 0; i < n; ++i) {
            positions[nums[i]].push_back(i);
        }
        
        int min_dist = INT_MAX;
        bool found = false;
        
        // Iterate through each value from 1 to 100
        for (int v = 1; v <= 100; ++v) {
            if (positions[v].size() >= 3) {
                found = true;
                // To minimize 2 * (k - i), we check consecutive triplets in the sorted indices
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