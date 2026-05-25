auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n - 1] == '1') return false;

        vector<int> q(n);
        int head = 0, tail = 0;
        q[tail++] = 0;
        
        int far = 0;

        while (head < tail) {
            int i = q[head++];
            if (i == n - 1) return true;

            int start = max(i + minJump, far + 1);
            int end = min(i + maxJump, n - 1);

            for (int j = start; j <= end; ++j) {
                if (s[j] == '0') {
                    if (j == n - 1) return true;
                    q[tail++] = j;
                }
            }
            far = max(far, end);
        }

        return false;
    }
};