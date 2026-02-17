#include <vector>
#include <string>
#include <bitset>

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        
        // Loop through every possible hour (0-11)
        for (int h = 0; h < 12; ++h) {
            // Loop through every possible minute (0-59)
            for (int m = 0; m < 60; ++m) {
                // __builtin_popcount counts the number of set bits (1s)
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    
                    // Format minutes with a leading zero if m < 10
                    string time = to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
                    result.push_back(time);
                }
            }
        }
        
        return result;
    }
};