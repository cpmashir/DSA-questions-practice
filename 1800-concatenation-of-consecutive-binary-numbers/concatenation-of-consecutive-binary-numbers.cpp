class Solution {
public:
    int concatenatedBinary(int n) {
        long long result = 0;
        int MOD = 1e9 + 7;
        int bitLength = 0;
        
        for (int i = 1; i <= n; ++i) {
            // If i is a power of 2, the number of bits needed increases
            if ((i & (i - 1)) == 0) {
                bitLength++;
            }
            
            // Shift result left by bitLength and add i
            // Formula: result = ((result << bitLength) + i) % MOD
            result = ((result << bitLength) | i) % MOD;
        }
        
        return (int)result;
    }
};