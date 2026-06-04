class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total_sum = 0;
        
        for (int i = num1; i <= num2; ++i) {
            // Any number with fewer than 3 digits (0 to 99) has a waviness of 0
            if (i < 100) continue;
            
            int temp = i;
            
            // Extract the first two digits from the right
            int right = temp % 10;
            temp /= 10;
            int curr = temp % 10;
            temp /= 10;
            
            // Iterate through the remaining digits
            while (temp > 0) {
                int left = temp % 10;
                
                // Check if 'curr' is a Peak
                if (curr > left && curr > right) {
                    total_sum++;
                }
                // Check if 'curr' is a Valley
                else if (curr < left && curr < right) {
                    total_sum++;
                }
                
                // Shift windows to the left for the next iteration
                right = curr;
                curr = left;
                temp /= 10;
            }
        }
        
        return total_sum;
    }
};