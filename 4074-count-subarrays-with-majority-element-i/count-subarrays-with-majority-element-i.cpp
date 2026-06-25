class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        // Optimize standard stream overhead
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                if (nums[j] == target) {
                    cnt++;
                }
                // Condition: strictly more than half of the elements are target
                if (cnt * 2 > (j - i + 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};