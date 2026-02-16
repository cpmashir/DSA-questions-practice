class Solution {
public:
    int reverseBits(int n) {
        unsigned int res = 0;
        unsigned int input = (unsigned int)n;
        
        for (int i = 0; i < 32; i++) {
            res = (res << 1) | (input & 1);
            input >>= 1;
        }
        
        return (int)res;
    }
};