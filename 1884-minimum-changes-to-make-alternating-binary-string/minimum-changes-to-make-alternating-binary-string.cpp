class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int count0 = 0; // Operations to match pattern "0101..."
        
        for (int i = 0; i < n; i++) {
            // In pattern "0101...", even indices should be '0', odd should be '1'
            if (i % 2 == 0) {
                if (s[i] != '0') count0++;
            } else {
                if (s[i] != '1') count0++;
            }
        }
        
        // The cost for the other pattern ("1010...") is simply (n - count0)
        return min(count0, n - count0);
    }
};