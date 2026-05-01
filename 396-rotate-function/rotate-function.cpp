class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0;
        long long f0 = 0;

        // Calculate the total sum of elements and the initial F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f0 += (long long)i * nums[i];
        }

        long long max_val = f0;
        long long current_f = f0;

        // Iteratively calculate F(k) using the derived relationship
        // We go backwards from the end of the array for the rotation logic
        for (int k = 1; k < n; k++) {
            // F(k) = F(k-1) + sum - n * last_element_of_previous_rotation
            current_f = current_f + sum - n * nums[n - k];
            max_val = max(max_val, current_f);
        }

        return (int)max_val;
    }
};