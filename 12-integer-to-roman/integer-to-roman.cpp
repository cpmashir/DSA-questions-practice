class Solution {
public:
    string intToRoman(int num) {
        // Define the mapping of values and symbols in descending order
        // We include the subtractive cases (4, 9, 40, etc.) as distinct entries
        vector<pair<int, string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        string result = "";
        
        for (int i = 0; i < romanMap.size(); i++) {
            // While the number is larger than the current roman value
            while (num >= romanMap[i].first) {
                result += romanMap[i].second; // Add the symbol
                num -= romanMap[i].first;    // Subtract the value
            }
        }
        
        return result;
    }
};