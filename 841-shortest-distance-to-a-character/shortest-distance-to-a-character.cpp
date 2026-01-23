#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> answer(n);
        int last_seen = -10001; 

        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                last_seen = i;
            }
            answer[i] = i - last_seen;
        }

        last_seen = 20001; 
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c) {
                last_seen = i;
            }
            answer[i] = min(answer[i], last_seen - i);
        }

        return answer;
    }
};