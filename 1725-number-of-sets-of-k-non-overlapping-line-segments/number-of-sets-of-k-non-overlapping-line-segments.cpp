class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int R = 2 * k;

        long long factN = 1, factR = 1, factNR = 1;

        for (int i = 1; i <= N; i++)
            factN = factN * i % MOD;

        for (int i = 1; i <= R; i++)
            factR = factR * i % MOD;

        for (int i = 1; i <= N - R; i++)
            factNR = factNR * i % MOD;

        return factN * power(factR, MOD - 2) % MOD
                    * power(factNR, MOD - 2) % MOD;
    }
};