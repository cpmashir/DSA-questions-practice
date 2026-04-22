class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        
        for (const string& q : queries) {
            for (const string& d : dictionary) {
                int edits = 0;
                bool possible = true;
                
                for (int i = 0; i < q.length(); ++i) {
                    if (q[i] != d[i]) {
                        edits++;
                    }
                    // Optimization: if edits exceed 2, this dictionary word fails
                    if (edits > 2) {
                        possible = false;
                        break;
                    }
                }
                
                if (possible) {
                    result.push_back(q);
                    // Found a match for this query, no need to check other dictionary words
                    break;
                }
            }
        }
        
        return result;
    }
};