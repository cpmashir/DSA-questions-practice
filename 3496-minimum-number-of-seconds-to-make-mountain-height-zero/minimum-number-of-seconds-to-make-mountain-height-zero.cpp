class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        // Find the minimum time factor to establish a tighter upper bound
        int minW = workerTimes[0];
        for (int w : workerTimes) if (w < minW) minW = w;

        long long low = 1;
        // Tighter upper bound: The fastest worker handles the whole mountain
        long long high = (long long)minW * mountainHeight * (mountainHeight + 1) / 2;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(mid, mountainHeight, workerTimes)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

private:
    bool isPossible(long long maxTime, int target, const vector<int>& workerTimes) {
        long long totalReduced = 0;
        for (int w : workerTimes) {
            // Solve: w * x * (x + 1) / 2 <= maxTime
            // x^2 + x - (2 * maxTime / w) <= 0
            long long limit = (2 * maxTime) / w;
            long long x = (sqrt(1 + 4 * limit) - 1) / 2;
            
            totalReduced += x;
            if (totalReduced >= target) return true;
        }
        return totalReduced >= target;
    }
};