class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int shift = k % n;
        
        if (shift == 0) return true;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != mat[i][(j + shift) % n]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};