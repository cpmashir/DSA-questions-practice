class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int val = 1 << (board[r][c] - '1');
                int b = (r / 3) * 3 + (c / 3);

                if ((rows[r] & val) || (cols[c] & val) || (boxes[b] & val)) {
                    return false;
                }

                rows[r] |= val;
                cols[c] |= val;
                boxes[b] |= val;
            }
        }

        return true;
    }
};