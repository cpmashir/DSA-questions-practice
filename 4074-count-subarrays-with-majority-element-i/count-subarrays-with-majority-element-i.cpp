class Solution {
private:
    vector<int> bit;
    int size;

    void update(int idx, int val) {
        for (; idx <= size; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        size = 2 * n + 5;
        bit.assign(size, 0);

        int count = 0;
        int prefix_sum = 0;
        int offset = n + 2;

        update(offset, 1);

        for (int num : nums) {
            prefix_sum += (num == target) ? 1 : -1;
            count += query(prefix_sum + offset - 1);
            update(prefix_sum + offset, 1);
        }

        return count;
    }
};