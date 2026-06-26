#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        static const char phoneMap[10][5] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        int total = 1;
        for (char d : digits) {
            int len = (d == '7' || d == '9') ? 4 : 3;
            total *= len;
        }

        vector<string> result(total, string(digits.length(), ' '));

        int repeat = total;
        for (int i = 0; i < digits.length(); ++i) {
            const char* letters = phoneMap[digits[i] - '0'];
            int len = (digits[i] == '7' || digits[i] == '9') ? 4 : 3;
            
            repeat /= len;
            int row = 0;
            
            while (row < total) {
                for (int l = 0; l < len; ++l) {
                    for (int r = 0; r < repeat; ++r) {
                        result[row++][i] = letters[l];
                    }
                }
            }
        }

        return result;
    }
};