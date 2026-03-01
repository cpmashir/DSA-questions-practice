class Solution {
public:
    int minPartitions(string n) {
        // The answer is simply the maximum digit in the string.
        // We initialize with '0' and iterate through the string.
        char max_digit = '0';
        for (char c : n) {
            if (c > max_digit) {
                max_digit = c;
            }
            // Optimization: If we find a '9', we can stop immediately.
            if (max_digit == '9') return 9;
        }
        return max_digit - '0';
    }
};