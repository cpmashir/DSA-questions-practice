class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> lastSeenReversed;
        lastSeenReversed.reserve(nums.size()); 
        int minDistance = -1;

        for (int j = 0; j < nums.size(); ++j) {
            auto it = lastSeenReversed.find(nums[j]);
            if (it != lastSeenReversed.end()) {
                int dist = j - it->second;
                if (minDistance == -1 || dist < minDistance) {
                    minDistance = dist;
                    if (minDistance == 1) return 1; 
                }
            }

            int n = nums[j];
            long rev = 0;
            while (n > 0) {
                rev = rev * 10 + (n % 10);
                n /= 10;
            }
            lastSeenReversed[(int)rev] = j;
        }

        return minDistance;
    }
};