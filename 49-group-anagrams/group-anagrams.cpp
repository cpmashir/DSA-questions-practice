class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        mp.reserve(strs.size());

        for (const string& s : strs) {
            int cnt[26] = {};

            for (char c : s)
                cnt[c - 'a']++;

            string key;
            key.reserve(52);

            for (int x : cnt) {
                key += '#';
                key += to_string(x);
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());

        for (auto& [key, group] : mp)
            ans.push_back(move(group));

        return ans;
    }
};