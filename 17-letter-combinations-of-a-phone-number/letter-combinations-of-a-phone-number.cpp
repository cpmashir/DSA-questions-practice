#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // Global keypad mapping where index matches the digit character value
    const vector<string> phoneMap = {
        "",     "",     "abc",  "def",  // 0, 1, 2, 3
        "ghi",  "jkl",  "mno",          // 4, 5, 6
        "pqrs", "tuv",  "wxyz"          // 7, 8, 9
    };

    void backtrack(const string& digits, int index, string& current, vector<string>& result) {
        // Base case: If the path length matches the input length, we found a valid combination
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Convert current char digit to its integer map index
        string letters = phoneMap[digits[index] - '0'];
        
        for (char letter : letters) {
            current.push_back(letter);                     // Choose
            backtrack(digits, index + 1, current, result); // Explore
            current.pop_back();                            // Undo Choose (Backtrack)
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        // Edge case: LeetCode constraints allow empty string input
        if (digits.empty()) {
            return result;
        }
        
        string current = "";
        backtrack(digits, 0, current, result);
        
        return result; // Ensures all execution paths return a value
    }
};