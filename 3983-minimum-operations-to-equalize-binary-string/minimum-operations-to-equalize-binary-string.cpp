class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int z = 0;
        for (char c : s) if (c == '0') z++;

        if (z == 0) return 0;

        // Sets to keep track of unvisited states by parity
        set<int> unvisited[2];
        for (int i = 0; i <= n; ++i) {
            unvisited[i % 2].insert(i);
        }

        queue<pair<int, int>> q; // {current_zeros, distance}
        q.push({z, 0});
        unvisited[z % 2].erase(z);

        while (!q.empty()) {
            auto [curr_z, d] = q.front();
            q.pop();

            // Calculate the range of next_z
            // next_z = curr_z + k - 2*i
            // i is flips of '0's. Max i = min(curr_z, k), Min i = max(0, k - (n - curr_z))
            int min_i = max(0, k - (n - curr_z));
            int max_i = min(curr_z, k);

            int next_z_min = curr_z + k - 2 * max_i;
            int next_z_max = curr_z + k - 2 * min_i;
            
            int parity = next_z_min % 2;
            auto& s_set = unvisited[parity];
            
            // Find all unvisited states in the range [next_z_min, next_z_max]
            auto it = s_set.lower_bound(next_z_min);
            while (it != s_set.end() && *it <= next_z_max) {
                if (*it == 0) return d + 1;
                
                q.push({*it, d + 1});
                it = s_set.erase(it); // Erase returns the next iterator
            }
        }

        return -1;
    }
};