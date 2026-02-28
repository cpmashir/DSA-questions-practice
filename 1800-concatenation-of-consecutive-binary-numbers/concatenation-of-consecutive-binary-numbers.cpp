class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 0;
        const int MOD = 1e9 + 7;
        
        for (int i = 1; i <= n; ++i) {
            // __builtin_clz(i) returns the number of leading zeros in a 32-bit int.
            // 32 - zeros = position of the highest set bit.
            int bitLength = 32 - __builtin_clz(i);
            
            // Shifting and ORing is generally faster than addition
            res = ((res << bitLength) | i) % MOD;
        }
        
        return (int)res;
    }
};