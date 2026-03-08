class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result = "";
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Access the i-th character of the i-th string
            char currentBit = nums[i][i];
            
            // Flip the bit and add it to our result
            result += (currentBit == '0' ? '1' : '0');
        }
        
        return result;
    }
};