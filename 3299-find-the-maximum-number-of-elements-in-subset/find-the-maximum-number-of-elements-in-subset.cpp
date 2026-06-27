#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int max_len = 1;
        
        int count_ones = 0;
        while (count_ones < n && nums[count_ones] == 1) {
            count_ones++;
        }
        if (count_ones > 0) {
            max_len = count_ones - (count_ones % 2 == 0);
        }
        
        for (int i = count_ones; i < n; ) {
            int j = i;
            while (j < n && nums[j] == nums[i]) {
                j++;
            }
            int freq = j - i;
            
            long long x = nums[i];
            i = j; 
            
            int current_len = 0;
            while (true) {
                auto it = lower_bound(nums.begin(), nums.end(), x);
                if (it == nums.end() || *it != x) {
                    current_len -= 1;
                    break;
                }
                
                auto it2 = upper_bound(it, nums.end(), x);
                int current_freq = distance(it, it2);
                
                if (current_freq >= 2) {
                    current_len += 2;
                    x = x * x;
                } else {
                    current_len += 1;
                    break;
                }
            }
            max_len = max(max_len, current_len);
        }
        
        return max_len;
    }
};