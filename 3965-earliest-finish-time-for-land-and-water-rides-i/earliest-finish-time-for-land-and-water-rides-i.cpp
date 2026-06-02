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
        int minFinishTime = 2e9;

        for (int i = 0; i < n; ++i) {
            int lStart = landStartTime[i];
            int lDur = landDuration[i];
            int lFinish = lStart + lDur;
            
            for (int j = 0; j < m; ++j) {
                int wStart = waterStartTime[j];
                int wDur = waterDuration[j];
                
                int f1 = max(lFinish, wStart) + wDur;
                int f2 = max(wStart + wDur, lStart) + lDur;
                
                if (f1 < minFinishTime) minFinishTime = f1;
                if (f2 < minFinishTime) minFinishTime = f2;
            }
        }

        return minFinishTime;
    }
};