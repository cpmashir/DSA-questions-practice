#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        unordered_set<long long> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert(((long long)obs[0] + 30000) << 32 | ((long long)obs[1] + 30000));
        }
        
        int x = 0, y = 0, dir = 0, maxDistSq = 0;
        
        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (int i = 0; i < cmd; ++i) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (obstacleSet.find(((long long)nx + 30000) << 32 | ((long long)ny + 30000)) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        maxDistSq = max(maxDistSq, x * x + y * y);
                    } else {
                        break;
                    }
                }
            }
        }
        
        return maxDistSq;
    }
};