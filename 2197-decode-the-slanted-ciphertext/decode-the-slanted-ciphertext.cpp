class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        int cols = n / rows;
        
        string res;
        res.reserve(n); 

        for (int i = 0; i < cols; ++i) {
            int max_steps = min(rows, cols - i);
            int curr = i;
            for (int step = 0; step < max_steps; ++step) {
                res += encodedText[curr];
                curr += cols + 1;
            }
        }

        int last = res.size() - 1;
        while (last >= 0 && res[last] == ' ') {
            --last;
        }
        res.resize(last + 1);
        
        return res;
    }
};