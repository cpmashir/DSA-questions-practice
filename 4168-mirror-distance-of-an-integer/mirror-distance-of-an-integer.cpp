class Solution {
public:
    int mirrorDistance(int n) {
        long long original = n;
        long long reversedN = 0;
        long long temp = n;
        
        while (temp > 0) {
            reversedN = reversedN * 10 + (temp % 10);
            temp /= 10;
        }
        
        return (int)std::abs(original - reversedN);
    }
};