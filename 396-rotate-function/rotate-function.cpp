class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0;
        long long current_f = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            current_f += (long long)i * nums[i];
        }

        long long max_val = current_f;

        for (int k = 1; k < n; k++) {
            current_f = current_f + sum - n * nums[n - k];
            if (current_f > max_val) {
                max_val = current_f;
            }
        }

        return (int)max_val;
    }
};