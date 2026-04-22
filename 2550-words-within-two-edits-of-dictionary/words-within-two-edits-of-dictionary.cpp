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
                    if (edits > 2) {
                        possible = false;
                        break;
                    }
                }
                
                if (possible) {
                    result.push_back(q);
                    break;
                }
            }
        }
        
        return result;
    }
};