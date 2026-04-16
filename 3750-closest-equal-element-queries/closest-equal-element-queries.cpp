class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos_map;
        
        for (int i = 0; i < n; ++i) {
            pos_map[nums[i]].push_back(i);
        }
        
        vector<int> min_dist_memo(n, -1);
        
        for (auto& [val, indices] : pos_map) {
            int m = indices.size();
            if (m < 2) continue;
            
            for (int k = 0; k < m; ++k) {
                int curr = indices[k];
                
                int next_idx = indices[(k + 1) % m];
                int d_next = abs(curr - next_idx);
                d_next = min(d_next, n - d_next);

                int prev_idx = indices[(k - 1 + m) % m];
                int d_prev = abs(curr - prev_idx);
                d_prev = min(d_prev, n - d_prev);

                min_dist_memo[curr] = min(d_next, d_prev);
            }
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        for (int q : queries) {
            answer.push_back(min_dist_memo[q]);
        }
        
        return answer;
    }
};