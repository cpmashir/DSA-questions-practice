class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int totalCount = 0;
        
        for (int i = left; i <= right; ++i) {
            // builtin_popcount is an efficient way to count set bits
            int bits = __builtin_popcount(i);
            
            // Check if bits is prime (up to 20)
            if (isPrime(bits)) {
                totalCount++;
            }
        }
        
        return totalCount;
    }

private:
    bool isPrime(int n) {
        // A simple set check is faster than a loop for small N
        return (n == 2 || n == 3 || n == 5 || n == 7 || 
                n == 11 || n == 13 || n == 17 || n == 19);
    }
};
