class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        
        // Step 1: Store all possible prefixes from arr1
        for (int num : arr1) {
            while (num > 0) {
                prefixes.insert(num);
                num /= 10; // Removes the last digit to get the next prefix
            }
        }
        
        int max_len = 0;
        
        // Step 2: Check prefixes of numbers in arr2
        for (int num : arr2) {
            while (num > 0) {
                // Early optimization: if the current number's length is less than 
                // or equal to our max_len, it can't possibly beat our record.
                string str_num = to_string(num);
                if (str_num.length() <= max_len) {
                    break; 
                }
                
                // If this prefix exists in arr1's prefix set
                if (prefixes.count(num)) {
                    max_len = max(max_len, (int)str_num.length());
                    break; // Since we go from longest to shortest, the first match is the best for this number
                }
                
                num /= 10;
            }
        }
        
        return max_len;
    }
};