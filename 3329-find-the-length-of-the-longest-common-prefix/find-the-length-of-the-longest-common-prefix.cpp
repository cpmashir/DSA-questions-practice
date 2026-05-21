class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        for (int num : arr1) {
            while (num > 0) {
                prefixes.insert(num);
                num /= 10;
            }
        }
        
        int max_len = 0;
        int p10 = 1; 
        
        for (int num : arr2) {
            while (num >= p10) {
                if (prefixes.count(num)) {
                    int len = 0;
                    int temp = num;
                    while (temp > 0) {
                        len++;
                        temp /= 10;
                    }
                    if (len > max_len) {
                        max_len = len;
                        p10 = 1;
                        for (int i = 0; i < max_len; ++i) p10 *= 10;
                    }
                    break;
                }
                num /= 10;
            }
        }
        
        return max_len;
    }
};