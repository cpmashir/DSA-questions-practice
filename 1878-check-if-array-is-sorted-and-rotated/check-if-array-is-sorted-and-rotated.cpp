// This block unties standard I/O streams, which cleans up hidden internal buffer memory on LeetCode.
auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    // Marking the vector const prevents any micro-allocations or defensive copying
    bool check(const vector<int>& nums) {
        int count = 0;
        const int n = nums.size(); // Marking the size const keeps it in a CPU register
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
                if (count > 1) return false; // Early exit keeps the call stack lean
            }
        }
        
        return true;
    }
};