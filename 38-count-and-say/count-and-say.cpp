#include <string>

class Solution {
public:
    string countAndSay(int n) {
        // Base case
        if (n == 1) return "1";
        
        string current = "1";
        
        // Iteratively generate the sequence up to n
        for (int i = 2; i <= n; ++i) {
            string next_seq = "";
            int len = current.length();
            
            // Look through the current string to build the run-length encoding
            for (int j = 0; j < len; ) {
                int count = 1;
                // Count consecutive identical characters
                while (j + count < len && current[j] == current[j + count]) {
                    count++;
                }
                
                // Append the count followed by the character
                next_seq += to_string(count) + current[j];
                
                // Move the index forward by the number of processed characters
                j += count;
            }
            
            // Move to the next iteration with the newly built string
            current = next_seq;
        }
        
        return current;
    }
};