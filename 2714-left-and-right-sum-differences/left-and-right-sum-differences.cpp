class Solution {
public:
    std::vector<int> leftRightDifference(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n);
        
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;
        int rightSum = totalSum;
        
        for (int i = 0; i < n; ++i) {
            rightSum -= nums[i];
            answer[i] = std::abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        
        return answer;
    }
};