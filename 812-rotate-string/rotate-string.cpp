class Solution {
public:
    bool rotateString(string s, string goal) {
        // If lengths are different, s can never become goal
        if (s.length() != goal.length()) {
            return false;
        }
        
        // Concatenate s with itself
        string doubled = s + s;
        
        // Check if goal is a substring of the doubled string
        // string::npos is returned if the substring is not found
        return doubled.find(goal) != string::npos;
    }
};