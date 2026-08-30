class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = min_element(nums.begin(), nums.end()) - nums.begin();
        int mx = max_element(nums.begin(), nums.end()) - nums.begin();
        int left = min(mn, mx);
        int right = max(mn, mx);
        
        return min({right + 1, n - left, left + 1 + n - right});
    }
};