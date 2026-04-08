#include <vector>

using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        int n = nums.size();

        // Process each query
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            long long v = query[3];

            // Update array elements based on the start index, range, and step
            for (int idx = l; idx <= r; idx += k) {
                // Perform multiplication and modulo operation
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }

        // Calculate the bitwise XOR of all final elements
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }

        return xorSum;
    }
};