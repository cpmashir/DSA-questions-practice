class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        long long l = 1, r = x / 2, ans = 1;

        while (l <= r) {
            long long mid = l + (r - l) / 2;

            if (mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};