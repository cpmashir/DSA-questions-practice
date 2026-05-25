class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        // If the last character is '1', we can never reach it.
        if (s[n - 1] == '1') return false;

        queue<int> q;
        q.push(0);
        
        // 'far' keeps track of the furthest index we've considered jumping to.
        int far = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            // If we've reached the last index, return true.
            if (i == n - 1) return true;

            // Start searching from the maximum of the minimum reachable jump 
            // and the furthest index we've already pushed/checked (+1).
            int start = max(i + minJump, far + 1);
            int end = min(i + maxJump, n - 1);

            for (int j = start; j <= end; ++j) {
                if (s[j] == '0') {
                    if (j == n - 1) return true;
                    q.push(j);
                }
            }

            // Update 'far' to the end of the current window so the next 
            // elements don't re-scan this range.
            far = max(far, end);
        }

        return false;
    }
};