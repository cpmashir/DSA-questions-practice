#include <vector>
#include <algorithm>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        int dp[1000];
        for (int i = 0; i < n; ++i) dp[i] = -1;
        dp[0] = 0;

        const int* ptr = nums.data();
        const long long t = target;

        for (int j = 1; j < n; ++j) {
            const int val_j = ptr[j];
            int best = -1;
            for (int i = 0; i < j; ++i) {
                if (dp[i] != -1) {
                    long long diff = (long long)val_j - ptr[i];
                    if (diff >= -t && diff <= t) {
                        if (dp[i] + 1 > best) best = dp[i] + 1;
                    }
                }
            }
            dp[j] = best;
        }
        return dp[n - 1];
    }
};