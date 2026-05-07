#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentPath;
        vector<bool> used(nums.size(), false);
        
        backtrack(nums, used, currentPath, result);
        
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& currentPath, vector<vector<int>>& result) {
        // Base Case: If current path length matches nums length, we found a permutation
        if (currentPath.size() == nums.size()) {
            result.push_back(currentPath);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // Skip if the number is already in the current permutation
            if (used[i]) continue;

            // 1. Action: Choose the number
            used[i] = true;
            currentPath.push_back(nums[i]);

            // 2. Recurse: Move to the next slot
            backtrack(nums, used, currentPath, result);

            // 3. Backtrack: Undo the choice to try other numbers for this slot
            currentPath.pop_back();
            used[i] = false;
        }
    }
};