class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s) ones += (c == '1');

        string t = "1" + s + "1";
        int n = t.size();

        int ans = ones;

        char c1 = 0, c2 = 0, c3 = 0;
        int l1 = 0, l2 = 0, l3 = 0;

        int i = 0;
        while (i < n) {
            char cur = t[i];
            int cnt = 0;
            while (i < n && t[i] == cur) {
                cnt++;
                i++;
            }

            c1 = c2; l1 = l2;
            c2 = c3; l2 = l3;
            c3 = cur; l3 = cnt;

            if (c1 == '0' && c2 == '1' && c3 == '0')
                ans = max(ans, ones + l1 + l3);
        }

        return ans;
    }
};