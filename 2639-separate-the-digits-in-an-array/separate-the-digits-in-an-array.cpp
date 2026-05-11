class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        
        for (int val : nums) {
            // Convert the number to a string to easily access digits in order
            string s = to_string(val);
            for (char c : s) {
                // Convert char back to int ('0' is ASCII 48)
                answer.push_back(c - '0');
            }
        }
        
        return answer;
    }
};