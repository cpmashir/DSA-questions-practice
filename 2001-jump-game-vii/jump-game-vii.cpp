class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n - 1] == '1') return false;

        int available_from = 0; 
        s[0] = '2'; 

        for (int i = 0; i < n; ++i) {
            if (s[i] != '2') continue;

            int start = max(i + minJump, available_from);
            int end = min(i + maxJump, n - 1);

            for (int j = start; j <= end; ++j) {
                if (s[j] == '0') {
                    s[j] = '2';
                }
            }
            available_from = max(available_from, end + 1);
            
            if (s[n - 1] == '2') return true;
        }

        return s[n - 1] == '2';
    }
};