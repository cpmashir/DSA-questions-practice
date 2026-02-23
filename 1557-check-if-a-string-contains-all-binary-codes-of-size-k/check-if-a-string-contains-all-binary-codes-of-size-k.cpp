class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int totalRequired = 1 << k;
        if (n < totalRequired + k - 1) return false;

        vector<bool> found(totalRequired, false);
        int count = 0;
        int currentMask = 0;
        int allOnes = totalRequired - 1; 

        for (int i = 0; i < n; ++i) {
            currentMask = ((currentMask << 1) & allOnes) | (s[i] - '0');

            if (i >= k - 1) {
                if (!found[currentMask]) {
                    found[currentMask] = true;
                    count++;
                    if (count == totalRequired) return true;
                }
            }
        }

        return false;
    }
};