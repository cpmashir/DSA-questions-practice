static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
    static int diff[200005]; 
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int max_sum = 2 * limit;
        
        fill(diff, diff + max_sum + 2, 0);

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            
            int mn = a < b ? a : b;
            int mx = a > b ? a : b;

            diff[2] += 2;
            diff[mn + 1] -= 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
            diff[mx + limit + 1] += 1;
        }

        int min_moves = n;
        int curr = 0;
        for (int i = 2; i <= max_sum; ++i) {
            curr += diff[i];
            if (curr < min_moves) min_moves = curr;
        }

        return min_moves;
    }
};

int Solution::diff[200005];