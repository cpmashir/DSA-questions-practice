class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        int cols = n / rows;
        string res;
        res.reserve(n);

        for (int i = 0; i < cols; ++i) {
            for (int curr = i; curr < n; curr += cols + 1) {
                res += encodedText[curr];
                if ((curr - i) / (cols + 1) == rows - 1) break;
            }
        }

        int last = res.find_last_not_of(' ');
        return (last == string::npos) ? "" : res.substr(0, last + 1);
    }
};