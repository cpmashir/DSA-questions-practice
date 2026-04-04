class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        if (rows == 1) return encodedText;
        
        int cols = n / rows;
        string res = "";
        
        // Each diagonal starts at (0, i) where i is the starting column
        for (int i = 0; i < cols; ++i) {
            for (int r = 0; r < rows; ++r) {
                int c = i + r; // The column shifts right as the row increases
                if (c < cols) {
                    // Map 2D (r, c) back to 1D index: row * total_cols + col
                    res += encodedText[r * cols + c];
                } else {
                    break; // Out of bounds for this diagonal
                }
            }
        }
        
        // Remove trailing spaces
        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }
        
        return res;
    }
};