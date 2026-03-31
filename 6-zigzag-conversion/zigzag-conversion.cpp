class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if (numRows <= 1 || n <= numRows) return s;

        string result;
        result.reserve(n);
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                result += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                    result += s[j + cycleLen - i];
                }
            }
        }
        return result;
    }
};