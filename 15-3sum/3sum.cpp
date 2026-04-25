class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort the array to use two pointers and handle duplicates
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int low = i + 1;
            int high = n - 1;

            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];

                if (sum == 0) {
                    result.push_back({nums[i], nums[low], nums[high]});
                    
                    // Skip duplicates for the second and third elements
                    while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;
                    
                    low++;
                    high--;
                } 
                else if (sum < 0) {
                    // Sum is too small, move low pointer to the right
                    low++;
                } 
                else {
                    // Sum is too large, move high pointer to the left
                    high--;
                }
            }
        }
        return result;
    }
};