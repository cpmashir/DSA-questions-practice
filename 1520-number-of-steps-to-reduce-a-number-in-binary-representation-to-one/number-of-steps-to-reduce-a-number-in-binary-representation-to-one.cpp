class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        int n = s.length();

        // We process from the last character up to the second character (index 1)
        // because the loop ends when we've reduced everything down to the first '1'.
        for (int i = n - 1; i > 0; --i) {
            int currentBit = s[i] - '0';

            if (currentBit + carry == 1) {
                // Number is odd: Add 1 (1 step) + Divide by 2 (1 step) = 2 steps
                steps += 2;
                carry = 1; 
            } else {
                // Number is even: Just divide by 2 (1 step)
                // If it was (0+0), carry stays 0. If it was (1+1), carry stays 1.
                steps += 1;
            }
        }

        // If at the end we have a carry (e.g., "1" became "10"), 
        // we need one more division to reach "1".
        return steps + carry;
    }
};