#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        unordered_map<int, vector<int>> groups;

        // Group indices by their values
        for (int i = 0; i < n; ++i) {
            groups[nums[i]].push_back(i);
        }

        // Process each group of indices
        for (auto const& [val, indices] : groups) {
            int k = indices.size();
            if (k <= 1) continue;

            // Calculate total sum of indices to help with suffix calculations
            long long total_sum = 0;
            for (int idx : indices) {
                total_sum += idx;
            }

            long long prefix_sum = 0;
            for (int i = 0; i < k; ++i) {
                long long current_idx = indices[i];
                
                // Sum of distances to the left: 
                // (number of elements to left * current_idx) - (sum of left indices)
                long long left_part = (1LL * i * current_idx) - prefix_sum;
                
                // Sum of distances to the right:
                // (sum of right indices) - (number of elements to right * current_idx)
                long long suffix_sum = total_sum - prefix_sum - current_idx;
                long long right_part = suffix_sum - (1LL * (k - 1 - i) * current_idx);
                
                arr[current_idx] = left_part + right_part;
                
                // Update prefix_sum for the next index in the group
                prefix_sum += current_idx;
            }
        }

        return arr;
    }
};