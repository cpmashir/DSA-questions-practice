class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, ones = 0;
        int minLen = n + 1;
        string ans = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                ones++;

            while (ones == k) {
                int len = right - left + 1;
                string cur = s.substr(left, len);

                if (len < minLen) {
                    minLen = len;
                    ans = cur;
                } else if (len == minLen && cur < ans) {
                    ans = cur;
                }

                if (s[left] == '1')
                    ones--;
                left++;
            }
        }

        return ans;
    }
};