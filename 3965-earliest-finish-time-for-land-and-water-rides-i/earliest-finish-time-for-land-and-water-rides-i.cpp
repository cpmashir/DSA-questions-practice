#include <vector>
#include <algorithm>

using namespace std;

auto speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int minLandFinish = 2e9;
        for (int i = 0; i < n; ++i) {
            int finish = landStartTime[i] + landDuration[i];
            if (finish < minLandFinish) {
                minLandFinish = finish;
            }
        }

        int minWaterFinish = 2e9;
        for (int j = 0; j < m; ++j) {
            int finish = waterStartTime[j] + waterDuration[j];
            if (finish < minWaterFinish) {
                minWaterFinish = finish;
            }
        }

        int ans1 = 2e9;
        for (int j = 0; j < m; ++j) {
            int f1 = max(minLandFinish, waterStartTime[j]) + waterDuration[j];
            if (f1 < ans1) ans1 = f1;
        }

        int ans2 = 2e9;
        for (int i = 0; i < n; ++i) {
            int f2 = max(minWaterFinish, landStartTime[i]) + landDuration[i];
            if (f2 < ans2) ans2 = f2;
        }

        return (ans1 < ans2) ? ans1 : ans2;
    }
};