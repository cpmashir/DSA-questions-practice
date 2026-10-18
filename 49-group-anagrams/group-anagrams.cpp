class Solution {
    struct Hash {
        size_t operator()(const array<int, 26>& a) const {
            size_t h = 0;
            for (int x : a)
                h = h * 31 + x;
            return h;
        }
    };

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, Hash> mp;
        mp.reserve(strs.size());

        for (auto& s : strs) {
            array<int, 26> cnt{};

            for (char c : s)
                cnt[c - 'a']++;

            mp[cnt].push_back(move(s));
        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());

        for (auto& entry : mp)
            ans.push_back(move(entry.second));

        return ans;
    }
};