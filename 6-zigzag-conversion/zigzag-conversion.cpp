class Solution {
public:
    string convert(string s, int numRows) {
        // If only 1 row is requested, or the string is too short to zigzag
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        // Create a vector of strings to represent each row
        vector<string> rows(min(numRows, (int)s.length()));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            
            // If we are at the top or bottom row, change direction
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move up or down based on direction
            currentRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows into a single string
        string result = "";
        for (string row : rows) {
            result += row;
        }

        return result;
    }
};