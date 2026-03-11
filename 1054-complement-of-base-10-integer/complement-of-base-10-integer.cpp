class Solution {
public:
    int bitwiseComplement(int n) {
        // Edge case: if n is 0, the complement is 1
        if (n == 0) return 1;

        // Find the number of bits in n
        // We create a mask that starts at 0 and fill it with 1s 
        // until it covers all bits of n.
        unsigned int mask = 0;
        int temp = n;
        
        while (temp > 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }
        
        // XOR flips the bits covered by the mask
        return n ^ mask;
    }
};