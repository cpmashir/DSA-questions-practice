class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int initial_zeros = 0;
        for (char c : s) if (c == '0') initial_zeros++;

        if (initial_zeros == 0) return 0;

        set<int> unvisited[2];
        for (int i = 0; i <= n; ++i) {
            unvisited[i % 2].insert(i);
        }

        queue<pair<int, int>> q;
        q.push({initial_zeros, 0});
        unvisited[initial_zeros % 2].erase(initial_zeros);

        while (!q.empty()) {
            auto [curr_z, d] = q.front();
            q.pop();

            int min_i = max(0, k - (n - curr_z));
            int max_i = min(curr_z, k);

            int next_z_min = curr_z + k - 2 * max_i;
            int next_z_max = curr_z + k - 2 * min_i;
            
            auto& s_set = unvisited[next_z_min % 2];
            auto it = s_set.lower_bound(next_z_min);
            
            while (it != s_set.end() && *it <= next_z_max) {
                if (*it == 0) return d + 1;
                q.push({*it, d + 1});
                it = s_set.erase(it);
            }
        }

        return -1;
    }
};