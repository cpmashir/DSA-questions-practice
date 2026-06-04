#include <string>
#include <vector>

class Solution {
private:
    // Helper function to calculate the waviness of a single number
    int getWaviness(int num) {
        // Any number with fewer than 3 digits has a waviness of 0
        if (num < 100) return 0;
        
        // Convert the number to a string to easily access individual digits
        std::string s = std::to_string(num);
        int waviness = 0;
        int n = s.length();
        
        // The first and last digits cannot be peaks or valleys, 
        // so we loop from index 1 to n - 2
        for (int i = 1; i < n - 1; ++i) {
            // Check for Peak: strictly greater than both neighbors
            if (s[i] > s[i - 1] && s[i] > s[i + 1]) {
                waviness++;
            }
            // Check for Valley: strictly less than both neighbors
            else if (s[i] < s[i - 1] && s[i] < s[i + 1]) {
                waviness++;
            }
        }
        
        return waviness;
    }

public:
    int totalWaviness(int num1, int num2) {
        int total_sum = 0;
        
        // Iterate through the inclusive range [num1, num2]
        for (int i = num1; i <= num2; ++i) {
            total_sum += getWaviness(i);
        }
        
        return total_sum;
    }
};