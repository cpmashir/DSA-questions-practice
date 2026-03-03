class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case: S1 is "0"
        if (n == 1) return '0';
        
        // Length of Sn is 2^n - 1
        int length = (1 << n) - 1;
        int mid = length / 2 + 1;
        
        if (k == mid) {
            return '1';
        } else if (k < mid) {
            // It's in the first half, which is Sn-1
            return findKthBit(n - 1, k);
        } else {
            // It's in the second half: reverse(invert(Sn-1))
            // Find the corresponding bit in Sn-1 from the end
            char bit = findKthBit(n - 1, length - k + 1);
            // Invert the bit
            return (bit == '0') ? '1' : '0';
        }
    }
};