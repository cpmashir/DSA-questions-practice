class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        answer.reserve(nums.size() * 4); 

        for (int val : nums) {
            int temp[6]; 
            int i = 0;
            
            while (val > 0) {
                temp[i++] = val % 10;
                val /= 10;
            }
            
            while (i > 0) {
                answer.push_back(temp[--i]);
            }
        }
        
        return answer;
    }
};