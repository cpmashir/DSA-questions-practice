class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, curr = 0;
        const int* p = nums.data();

        for (int i = 0; i < n; ++i) {
            sum += p[i];
            curr += (long long)i * p[i];
        }

        long long res = curr;
        for (int i = n - 1; i > 0; --i) {
            curr += sum - (long long)n * p[i];
            if (curr > res) res = curr;
        }

        return (int)res;
    }
};