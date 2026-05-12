class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool neg = (dividend > 0) ^ (divisor > 0);
        
        // Cast to unsigned int BEFORE negation to handle INT_MIN safely
        unsigned int a = (dividend == INT_MIN) ? (unsigned int)INT_MAX + 1 : abs(dividend);
        unsigned int b = (divisor == INT_MIN) ? (unsigned int)INT_MAX + 1 : abs(divisor);
        unsigned int res = 0;

        for (int i = 31; i >= 0; i--) {
            if ((a >> i) >= b) {
                res += (1U << i);
                a -= (b << i);
            }
        }

        return neg ? -res : res;
    }
};