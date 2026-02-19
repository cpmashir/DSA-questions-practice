class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, prev = 0, i = 0, n = s.length();
        while (i < n) {
            int curr = 0;
            char c = s[i];
            while (i < n && s[i] == c) {
                curr++;
                i++;
            }
            ans += (prev < curr ? prev : curr);
            prev = curr;
        }
        return ans;
    }
};