#include <vector>
#include <numeric>
#include <cmath>

class Solution {
public:
    std::vector<int> leftRightDifference(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n);
        
        // Calculate the total sum of the array
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;
        int rightSum = totalSum;
        
        for (int i = 0; i < n; ++i) {
            // rightSum for index i is the total remaining sum minus the current element
            rightSum -= nums[i];
            
            // Calculate the absolute difference
            answer[i] = std::abs(leftSum - rightSum);
            
            // Update leftSum for the next index
            leftSum += nums[i];
        }
        
        return answer;
    }
};