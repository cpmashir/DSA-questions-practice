#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.length();
        
        bool sorted = true;
        char min_char = s[0];
        char max_char = s[0];
        int count[26] = {0};

        for (int i = 0; i < n; ++i) {
            count[s[i] - 'a']++;
            if (i > 0 && s[i] < s[i - 1]) sorted = false;
            if (s[i] < min_char) min_char = s[i];
            if (s[i] > max_char) max_char = s[i];
        }

        if (sorted) return 0;
        if (n <= 2) return -1;

        if (s[0] == min_char || s[n - 1] == max_char) return 1;

        bool min_in_prefix = false;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == min_char) {
                min_in_prefix = true;
                break;
            }
        }

        bool max_in_suffix = false;
        for (int i = 1; i < n; ++i) {
            if (s[i] == max_char) {
                max_in_suffix = true;
                break;
            }
        }

        if (min_in_prefix || max_in_suffix) return 2;

        return 3;
    }
};