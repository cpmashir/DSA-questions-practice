#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case: overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        // true if result should be negative
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to handle INT_MIN absolute value
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);
        
        long long quotient = 0;

        // Main logic: Bit manipulation
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            // Double the divisor until it's larger than the remaining dividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            // Subtract the largest found multiple of the divisor
            absDividend -= tempDivisor;
            quotient += multiple;
        }

        return isNegative ? -quotient : quotient;
    }
};