class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        unordered_set<long long> obs;
        obs.reserve(obstacles.size());

        for (auto &o : obstacles) {
            long long key = ((long long)o[0] << 32) | (unsigned int)o[1];
            obs.insert(key);
        }

        int x = 0, y = 0;
        int dir = 0;

        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};

        int maxDist = 0;

        for (int cmd : commands) {

            if (cmd == -1) {
                dir = (dir + 1) & 3;
            } 
            else if (cmd == -2) {
                dir = (dir + 3) & 3;
            } 
            else {

                while (cmd--) {

                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    long long key = ((long long)nx << 32) | (unsigned int)ny;

                    if (obs.count(key)) break;

                    x = nx;
                    y = ny;

                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};