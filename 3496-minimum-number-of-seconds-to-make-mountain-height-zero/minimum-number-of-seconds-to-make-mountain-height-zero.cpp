class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1;
        // Upper bound: slowest worker taking the whole mountain
        // Max W = 10^6, Max H = 10^5. Max time approx 10^6 * (10^5 * 10^5 / 2)
        long long high = 1e18; 
        long long ans = high;

        // Find a tighter upper bound based on the best worker to speed up search
        int minWorker = *min_element(workerTimes.begin(), workerTimes.end());
        high = (long long)minWorker * mountainHeight * (mountainHeight + 1) / 2;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canReduce(mid, mountainHeight, workerTimes)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

private:
    bool canReduce(long long time, int targetHeight, vector<int>& workerTimes) {
        long long totalHeightReduced = 0;
        for (int w : workerTimes) {
            // Solve: w * x * (x + 1) / 2 <= time
            // x^2 + x - (2 * time / w) <= 0
            long long val = (2 * time) / w;
            long long x = (sqrt(1 + 4 * val) - 1) / 2;
            
            totalHeightReduced += x;
            if (totalHeightReduced >= targetHeight) return true;
        }
        return totalHeightReduced >= targetHeight;
    }
};