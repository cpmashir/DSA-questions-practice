class Solution {
public:
    int reverseInt(int n) {
        long rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return (int)rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> lastSeenReversed;
        int minDistance = INT_MAX;
        bool found = false;

        for (int j = 0; j < nums.size(); ++j) {
            if (lastSeenReversed.count(nums[j])) {
                minDistance = min(minDistance, j - lastSeenReversed[nums[j]]);
                found = true;
            }
            lastSeenReversed[reverseInt(nums[j])] = j;
        }

        return found ? minDistance : -1;
    }
};