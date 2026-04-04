class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        if (n == 0) return "";
        
        int cols = n / rows;
        string res;
        res.reserve(n); 

        for (int i = 0; i < cols; ++i) {
            for (int j = i; j < n; j += cols + 1) {
                res += encodedText[j];
                if (res.length() % rows == 0 && i + (rows - 1) * (cols + 1) == j) break;
            }
        }

        int last = res.size() - 1;
        while (last >= 0 && res[last] == ' ') {
            last--;
        }
        
        res.resize(last + 1);
        return res;
    }
};