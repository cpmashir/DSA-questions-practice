class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr = 1; // Current group length
        int prev = 0; // Previous group length
        int result = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                curr++;
            } else {
                // We reached a transition, add the matches found so far
                result += min(prev, curr);
                // Move current group count to previous, reset current
                prev = curr;
                curr = 1;
            }
        }
        
        // Final addition for the last pair of groups
        return result + min(prev, curr);
    }
};