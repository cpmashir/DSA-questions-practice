#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // Use a lambda to define the custom sorting criteria
        std::sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            
            // If bit counts are different, sort by bit count
            if (countA != countB) {
                return countA < countB;
            }
            // Otherwise, sort by the value of the numbers themselves
            return a < b;
        });
        
        return arr;
    }
};