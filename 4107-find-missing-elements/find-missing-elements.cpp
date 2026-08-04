class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        bool present[101] = {false};

        int mn = 101, mx = 0;
        for (int x : nums) {
            present[x] = true;
            mn = min(mn, x);
            mx = max(mx, x);
        }

        vector<int> ans;
        for (int x = mn + 1; x < mx; x++) {
            if (!present[x])
                ans.push_back(x);
        }

        return ans;
    }
};