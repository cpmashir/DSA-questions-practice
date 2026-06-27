#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        int max_len = 1; // Any single element can form a valid sequence of length 1

        // Handle the special case for 1
        if (counts.count(1)) {
            int count_ones = counts[1];
            if (count_ones % 2 == 0) {
                max_len = max(max_len, count_ones - 1);
            } else {
                max_len = max(max_len, count_ones);
            }
        }

        // Check for patterns starting with x > 1
        for (auto& [val, count] : counts) {
            if (val == 1) continue;

            long long x = val;
            int current_len = 0;

            // While we have at least 2 copies, we can place them on both sides
            while (counts.count(x) && counts[x] >= 2) {
                current_len += 2;
                x = x * x; // Move to the next square
            }

            // If the current peak element exists at least once, it completes the peak
            if (counts.count(x) && counts[x] >= 1) {
                current_len += 1;
            } else {
                // If the peak element doesn't exist, the previous element must act as the peak.
                // We previously added 2 copies of it, so we reduce it by 1 to make it the peak.
                current_len -= 1;
            }

            max_len = max(max_len, current_len);
        }

        return max_len;
    }
};