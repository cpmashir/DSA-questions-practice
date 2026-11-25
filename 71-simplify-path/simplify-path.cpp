class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string dir;
        stringstream ss(path);

        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") continue;
            if (dir == "..") {
                if (!v.empty()) v.pop_back();
            } else {
                v.push_back(dir);
            }
        }

        string ans;
        for (auto &s : v) ans += "/" + s;

        return ans.empty() ? "/" : ans;
    }
};