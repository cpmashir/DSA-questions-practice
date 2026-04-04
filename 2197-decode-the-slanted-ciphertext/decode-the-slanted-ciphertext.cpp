class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        if (n == 0) return "";
        
        int cols = n / rows;
        string res;
        res.reserve(n);

        for (int i = 0; i < cols; ++i) {
            int curr = i;
            for (int r = 0; r < rows && curr < n; ++r) {
                res += encodedText[curr];
                curr += (cols + 1);
                if (curr % cols == 0 && r < rows - 1) break; 
            }
        }

        int last = res.find_last_not_of(' ');
        if (last == string::npos) return "";
        res.erase(last + 1);

        return res;
    }
};