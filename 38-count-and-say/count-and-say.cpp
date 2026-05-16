#include <string>
#include <utility>

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string current = "1";
        string next_seq;
        
        // Pre-reserve memory to avoid multiple reallocations during execution
        // The maximum length for n = 30 is well under 5000 characters
        current.reserve(5000);
        next_seq.reserve(5000);
        
        for (int i = 2; i <= n; ++i) {
            next_seq.clear(); // Clear the buffer without freeing the allocated memory capacity
            int len = current.length();
            
            for (int j = 0; j < len; ) {
                int count = 1;
                while (j + count < len && current[j] == current[j + count]) {
                    count++;
                }
                
                // Micro-optimization: Fast integer-to-char conversion 
                // because count will only ever be 1, 2, or 3
                next_seq.push_back('0' + count);
                next_seq.push_back(current[j]);
                
                j += count;
            }
            
            // Swap pointers/buffers instead of copying data
            std::swap(current, next_seq);
        }
        
        return current;
    }
};