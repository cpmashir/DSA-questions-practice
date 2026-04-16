#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos_map;
        
        // Step 1: Map each value to its list of indices
        for (int i = 0; i < n; ++i) {
            pos_map[nums[i]].push_back(i);
        }
        
        // Step 2: Precompute the minimum distance for every index that has duplicates
        // We use an unordered_map to store the precomputed result for each index
        unordered_map<int, int> min_dist_memo;
        
        for (auto& entry : pos_map) {
            const vector<int>& indices = entry.second;
            int m = indices.size();
            
            if (m <= 1) {
                // If the value appears only once, distance is -1
                for (int idx : indices) min_dist_memo[idx] = -1;
                continue;
            }
            
            for (int k = 0; k < m; ++k) {
                int curr_idx = indices[k];
                
                // Neighbors in the sorted list (with wrap-around)
                int prev_idx = indices[(k - 1 + m) % m];
                int next_idx = indices[(k + 1) % m];
                
                // Calculate circular distance to previous neighbor
                int dist1 = abs(curr_idx - prev_idx);
                dist1 = min(dist1, n - dist1);
                
                // Calculate circular distance to next neighbor
                int dist2 = abs(curr_idx - next_idx);
                dist2 = min(dist2, n - dist2);
                
                min_dist_memo[curr_idx] = min(dist1, dist2);
            }
        }
        
        // Step 3: Fill the answer array based on queries
        vector<int> answer;
        answer.reserve(queries.size());
        for (int q : queries) {
            answer.push_back(min_dist_memo[q]);
        }
        
        return answer;
    }
};