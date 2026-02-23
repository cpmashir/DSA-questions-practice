class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // If the string length is less than the required unique combinations + k - 1, 
        // it's mathematically impossible to contain all codes.
        if (s.length() < (1 << k) + k - 1) return false;

        unordered_set<string> foundCodes;
        int totalRequired = 1 << k; // This is 2^k

        for (int i = 0; i <= (int)s.length() - k; ++i) {
            foundCodes.insert(s.substr(i, k));
            
            // Optimization: If we found all codes, stop early
            if (foundCodes.size() == totalRequired) {
                return true;
            }
        }

        return foundCodes.size() == totalRequired;
    }
};
