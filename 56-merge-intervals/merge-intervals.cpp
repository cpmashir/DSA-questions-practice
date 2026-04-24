#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return intervals;

        sort(intervals.begin(), intervals.end());

        int count = 0;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= intervals[count][1]) {
                intervals[count][1] = max(intervals[count][1], intervals[i][1]);
            } else {
                count++;
                intervals[count] = intervals[i];
            }
        }
        
        intervals.erase(intervals.begin() + count + 1, intervals.end());
        return intervals;
    }
};