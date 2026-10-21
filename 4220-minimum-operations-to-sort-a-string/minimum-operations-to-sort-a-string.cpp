#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.length();
        
        std::string t = s;
        std::sort(t.begin(), t.end());
        
        // 0 operations if already sorted
        if (s == t) return 0;
        
        // Cannot sort a string of length <= 2 with proper substrings
        if (n <= 2) return -1;
        
        // 1 operation if the first or last character is already in its correct place
        if (s[0] == t[0] || s[n - 1] == t[n - 1]) {
            return 1;
        }
        
        // Check if the global minimum exists in s[0 ... n-2]
        bool min_in_prefix = false;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == t[0]) {
                min_in_prefix = true;
                break;
            }
        }
        
        // Check if the global maximum exists in s[1 ... n-1]
        bool max_in_suffix = false;
        for (int i = 1; i < n; ++i) {
            if (s[i] == t[n - 1]) {
                max_in_suffix = true;
                break;
            }
        }
        
        // 2 operations if we can place the min at index 0 or max at index n-1 in 1 move
        if (min_in_prefix || max_in_suffix) {
            return 2;
        }
        
        // Otherwise, exactly 3 operations are needed
        return 3;
    }
};