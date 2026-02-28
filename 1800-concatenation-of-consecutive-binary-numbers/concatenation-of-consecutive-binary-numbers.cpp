class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 0;
        const int MOD = 1e9 + 7;
        for (int i = 1; i <= n; ++i) {
            res = ((res << (32 - __builtin_clz(i))) | i) % MOD;
        }
        return (int)res;
    }
};