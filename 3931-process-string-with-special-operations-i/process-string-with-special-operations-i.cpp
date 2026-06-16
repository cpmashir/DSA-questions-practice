#include <string>
#include <algorithm>

class Solution {
public:
    string processStr(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        string result = "";
        result.reserve(128); 
        
        for (const char c : s) {
            switch (c) {
                case '*':
                    if (!result.empty()) {
                        result.pop_back();
                    }
                    break;
                case '#':
                    if (!result.empty()) {
                        result.append(result);
                    }
                    break;
                case '%':
                    if (result.length() > 1) {
                        std::reverse(result.begin(), result.end());
                    }
                    break;
                default:
                    result.push_back(c);
                    break;
            }
        }
        
        return result;
    }
};