class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = box.size();
        int n = box[0].size();
        
        vector<vector<char>> res(n, vector<char>(m, '.'));

        for (int i = 0; i < m; ++i) {
            int lowestEmpty = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '#') {
                    res[lowestEmpty][m - 1 - i] = '#';
                    lowestEmpty--;
                } else if (box[i][j] == '*') {
                    res[j][m - 1 - i] = '*';
                    lowestEmpty = j - 1;
                }
            }
        }
        
        return res;
    }
};