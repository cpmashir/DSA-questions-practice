#include <vector>
#include <string>

using namespace std;

static const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> last(m + 1, -1);
        last[0] = n;

        for (int k = 1, idx = n - 1; k <= m; ++k) {
            while (idx >= 0 && word1[idx] != word2[m - k]) {
                idx--;
            }
            if (idx < 0) break;
            last[k] = idx--;
        }

        vector<int> result;
        result.reserve(m);
        
        int word1_idx = 0;
        bool used_mismatch = false;

        for (int i = 0; i < m; ++i) {
            bool found = false;
            while (word1_idx < n) {
                if (word1[word1_idx] == word2[i]) {
                    result.push_back(word1_idx++);
                    found = true;
                    break;
                }
                if (!used_mismatch && last[m - 1 - i] > word1_idx) {
                    used_mismatch = true;
                    result.push_back(word1_idx++);
                    found = true;
                    break;
                }
                word1_idx++;
            }
            if (!found) return {};
        }

        return result;
    }
};