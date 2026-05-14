#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
    bool isGood(std::vector<int>& nums) {
        int len = nums.size();
        
        // Find the maximum element in the array to determine 'n'
        int n = 0;
        for (int x : nums) {
            if (x > n) n = x;
        }

        // According to base[n], the length must be n + 1
        if (len != n + 1) {
            return false;
        }

        // Count occurrences of each number
        std::vector<int> counts(n + 1, 0);
        for (int x : nums) {
            // If a number is outside the valid range [1, n], it's not good
            if (x < 1 || x > n) return false;
            counts[x]++;
        }

        // Validate the requirements for base[n]
        for (int i = 1; i < n; ++i) {
            if (counts[i] != 1) return false; // 1 to n-1 must appear once
        }
        
        return counts[n] == 2; // n must appear twice
    }
};