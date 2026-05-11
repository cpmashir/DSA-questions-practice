class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        for (int val : nums) {
            vector<int> temp;
            while (val > 0) {
                temp.push_back(val % 10);
                val /= 10;
            }
            // Reverse the digits and add to the main answer
            for (int i = temp.size() - 1; i >= 0; i--) {
                answer.push_back(temp[i]);
            }
        }
        return answer;
    }
};