class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        int freq[2005]; 
        memset(freq, 0, sizeof(freq));

        int count = 0;
        int prefix_sum = 0;
        int offset = n;
        
        freq[offset] = 1;
        int valid_subarrays_count = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                valid_subarrays_count += freq[prefix_sum + offset];
                prefix_sum++;
            } else {
                prefix_sum--;
                valid_subarrays_count -= freq[prefix_sum + offset];
            }
            count += valid_subarrays_count;
            freq[prefix_sum + offset]++;
        }

        return count;
    }
};