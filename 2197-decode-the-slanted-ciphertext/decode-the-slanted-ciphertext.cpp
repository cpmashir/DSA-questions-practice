class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        int cols = n / rows;
        string res;
        res.reserve(n / rows); // Pre-allocate memory to avoid reallocations

        for (int i = 0; i < cols; ++i) {
            for (int j = i; j < n; j += cols + 1) {
                res += encodedText[j];
                
                // If we've reached the last row for this diagonal, 
                // the next increment might jump into the next starting diagonal's path,
                // so we handle the diagonal length naturally via the loop condition 'j < n'.
                // However, we must ensure we don't exceed the 'rows' limit for each diagonal.
                if ((j - i) / (cols + 1) == rows - 1) break;
            }
        }

        while (!res.empty() && res.back() == ' ') res.pop_back();
        return res;
    }
};