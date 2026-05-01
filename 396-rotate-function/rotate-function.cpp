class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0, curr = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            curr += (long long)i * nums[i];
        }
        long long res = curr;
        for (int i = n - 1; i > 0; --i) {
            curr += sum - n * nums[i];
            if (curr > res) res = curr;
        }
        return (int)res;
    }
};