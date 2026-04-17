#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Helper function to reverse digits of a number
    int reverseInt(int n) {
        long rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return (int)rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        // maps the value 'reverse(nums[i])' to the last seen index 'i'
        unordered_map<int, int> lastSeenReversed;
        int minDistance = INT_MAX;
        bool found = false;

        for (int j = 0; j < nums.size(); ++j) {
            // Check if current nums[j] matches any reverse(nums[i]) seen before
            if (lastSeenReversed.count(nums[j])) {
                minDistance = min(minDistance, j - lastSeenReversed[nums[j]]);
                found = true;
            }

            // Store/Update the reverse of the current number and its index
            // We update it every time because a later index 'i' for the same 
            // reversed value will always yield a smaller distance for future 'j's.
            lastSeenReversed[reverseInt(nums[j])] = j;
        }

        return found ? minDistance : -1;
    }
};