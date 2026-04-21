class Solution {
    struct DSU {
        std::vector<int> parent;
        DSU(int n) {
            parent.resize(n);
            std::iota(parent.begin(), parent.end(), 0);
        }
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        void unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) parent[root_i] = root_j;
        }
    };

public:
    int minimumHammingDistance(std::vector<int>& source, std::vector<int>& target, std::vector<std::vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);

        for (const auto& swap : allowedSwaps) {
            dsu.unite(swap[0], swap[1]);
        }

        std::unordered_map<int, std::unordered_map<int, int>> components;
        for (int i = 0; i < n; ++i) {
            components[dsu.find(i)][source[i]]++;
        }

        int hamming_distance = 0;
        for (int i = 0; i < n; ++i) {
            int root = dsu.find(i);
            if (components[root].count(target[i]) && components[root][target[i]] > 0) {
                components[root][target[i]]--;
            } else {
                hamming_distance++;
            }
        }

        return hamming_distance;
    }
};