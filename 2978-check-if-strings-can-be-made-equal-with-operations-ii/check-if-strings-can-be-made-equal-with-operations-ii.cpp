class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        // Frequency arrays for even and odd positions
        vector<int> evenCount1(26, 0), oddCount1(26, 0);
        vector<int> evenCount2(26, 0), oddCount2(26, 0);

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                evenCount1[s1[i] - 'a']++;
                evenCount2[s2[i] - 'a']++;
            } else {
                oddCount1[s1[i] - 'a']++;
                oddCount2[s2[i] - 'a']++;
            }
        }

        // If the frequency distributions match for both parities, 
        // the strings can be made equal.
        return (evenCount1 == evenCount2 && oddCount1 == oddCount2);
    }
};