class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int minW = workerTimes[0];
        for (int w : workerTimes) if (w < minW) minW = w;

        long long low = 1;
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
        
            long long limit = (2 * maxTime) / w;
            long long x = (sqrt(1 + 4 * limit) - 1) / 2;
            
            totalReduced += x;
            if (totalReduced >= target) return true;
        }
        return totalReduced >= target;
    }
};