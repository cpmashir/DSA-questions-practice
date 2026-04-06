#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions: North, East, South, West
        // dy/dx changes for each direction index
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        // Store obstacles in a set for O(1) lookup
        // We use a custom hash or string to represent the coordinates
        unordered_set<string> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }
        
        int x = 0, y = 0;    // Starting position
        int dir = 0;         // Initially facing North
        int maxDistSq = 0;
        
        for (int cmd : commands) {
            if (cmd == -1) {
                // Turn right
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                // Turn left
                dir = (dir + 3) % 4;
            } else {
                // Move forward 'cmd' units
                for (int i = 0; i < cmd; ++i) {
                    int nextX = x + dx[dir];
                    int nextY = y + dy[dir];
                    
                    // Check if the next step is an obstacle
                    if (obstacleSet.find(to_string(nextX) + "," + to_string(nextY)) == obstacleSet.end()) {
                        x = nextX;
                        y = nextY;
                        // Update maximum distance squared
                        maxDistSq = max(maxDistSq, x * x + y * y);
                    } else {
                        // Hit an obstacle, stop moving for this command
                        break;
                    }
                }
            }
        }
        
        return maxDistSq;
    }
};