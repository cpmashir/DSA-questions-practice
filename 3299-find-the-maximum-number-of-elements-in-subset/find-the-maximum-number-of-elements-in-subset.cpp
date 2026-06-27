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

        int max_len = 1;

        if (counts.count(1)) {
            int count_ones = counts[1];
            max_len = max(max_len, count_ones - (count_ones % 2 == 0));
        }

        for (auto& [val, count] : counts) {
            if (val == 1) continue;

            long long x = val;
            int current_len = 0;

            while (counts.count(x) && counts[x] >= 2) {
                current_len += 2;
                x = x * x;
            }

            if (counts.count(x)) {
                current_len += 1;
            } else {
                current_len -= 1;
            }

            max_len = max(max_len, current_len);
        }

        return max_len;
    }
};