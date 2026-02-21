class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int totalCount = 0;
        for (int i = left; i <= right; ++i) {
            int bits = __builtin_popcount(i);
            if ((665772 >> bits) & 1) {
                totalCount++;
            }
        }
        return totalCount;
    }
};