class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;

        long long x = 0, p = 1;
        int sum = 0;

        while (n) {
            int d = n % 10;
            if (d) {
                x += 1LL * d * p;
                p *= 10;
                sum += d;
            }
            n /= 10;
        }

        return x * sum;
    }
};