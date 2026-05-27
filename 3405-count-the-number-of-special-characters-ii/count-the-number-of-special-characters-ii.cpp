class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool has_lower[26] = {false};
        bool has_upper[26] = {false};
        bool invalid[26] = {false};

        for (char ch : word) {
            if (ch >= 'a' && ch <= 'z') {
                int idx = ch - 'a';
                has_lower[idx] = true;
                if (has_upper[idx]) {
                    invalid[idx] = true;
                }
            } else {
                int idx = ch - 'A';
                has_upper[idx] = true;
            }
        }

        int special_count = 0;
        for (int i = 0; i < 26; ++i) {
            if (has_lower[i] && has_upper[i] && !invalid[i]) {
                special_count++;
            }
        }

        return special_count;
    }
};