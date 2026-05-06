class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        // Pre-allocate the rotated dimensions: n rows, m columns
        vector<vector<char>> res(n, vector<char>(m, '.'));

        for (int i = 0; i < m; ++i) {
            int lowestEmpty = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '#') {
                    // Place the stone at the lowest available spot in the NEW orientation
                    // Original (i, j) after 90 deg rotation becomes (j, m - 1 - i)
                    res[lowestEmpty][m - 1 - i] = '#';
                    lowestEmpty--;
                } else if (box[i][j] == '*') {
                    // Obstacles don't move, place it exactly where it belongs
                    res[j][m - 1 - i] = '*';
                    lowestEmpty = j - 1;
                }
            }
        }
        
        return res;
    }
};