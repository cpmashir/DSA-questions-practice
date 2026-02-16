class Solution {
public:
    int reverseBits(int n) {
        unsigned int res = 0;
        unsigned int input = (unsigned int)n; // Treat as unsigned for bit logic
        
        for (int i = 0; i < 32; i++) {
            // Shift result left and add the LSB of input
            res = (res << 1) | (input & 1);
            // Shift input right to get the next bit
            input >>= 1;
        }
        
        return (int)res;
    }
};