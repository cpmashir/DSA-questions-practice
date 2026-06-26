#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
private:
    const vector<string> phoneMap = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(const string& digits, int index, string& current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        const string& letters = phoneMap[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1, current, result);
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        int totalCombinations = 1;
        for (char d : digits) {
            totalCombinations *= (d == '7' || d == '9') ? 4 : 3;
        }
        
        vector<string> result;
        result.reserve(totalCombinations);
        
        string current = "";
        current.reserve(digits.length());
        
        backtrack(digits, 0, current, result);
        return result;
    }
};