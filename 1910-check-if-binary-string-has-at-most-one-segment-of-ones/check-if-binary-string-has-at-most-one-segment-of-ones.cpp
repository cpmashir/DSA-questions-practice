class Solution {
public:
    bool checkOnesSegment(string s) {
        // Since s[0] is '1', we just need to make sure 
        // there is no '1' after the first group of '1's ends.
        // This is equivalent to checking if "01" is a substring.
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i-1] == '0' && s[i] == '1') {
                return false;
            }
        }
        return true;
    }
};