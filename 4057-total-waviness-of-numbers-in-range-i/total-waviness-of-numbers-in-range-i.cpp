class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total_sum = 0;
        
        for (int i = num1; i <= num2; ++i) {
            if (i < 100) continue;
            
            int temp = i;
            int right = temp % 10;
            temp /= 10;
            int curr = temp % 10;
            temp /= 10;
            
            while (temp > 0) {
                int left = temp % 10;
                
                if (curr > left && curr > right) {
                    total_sum++;
                }
                else if (curr < left && curr < right) {
                    total_sum++;
                }
                
                right = curr;
                curr = left;
                temp /= 10;
            }
        }
        
        return total_sum;
    }
};