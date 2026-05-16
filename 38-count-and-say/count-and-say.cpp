class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string current = "1";
        string next_seq;
        
        current.reserve(5000);
        next_seq.reserve(5000);
        
        for (int i = 2; i <= n; ++i) {
            next_seq.clear();
            int len = current.length();
            
            for (int j = 0; j < len; ) {
                int count = 1;
                while (j + count < len && current[j] == current[j + count]) {
                    count++;
                }
                
                next_seq.push_back('0' + count);
                next_seq.push_back(current[j]);
                
                j += count;
            }
            
            std::swap(current, next_seq);
        }
        
        return current;
    }
};