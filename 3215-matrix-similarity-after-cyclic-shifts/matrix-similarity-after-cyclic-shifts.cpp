class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // We only care about k % n because shifting n times 
        // returns the row to its original state.
        int shift = k % n;
        
        if (shift == 0) return true;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If the current element doesn't match the element
                // at the shifted position, the matrices aren't identical.
                if (mat[i][j] != mat[i][(j + shift) % n]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};