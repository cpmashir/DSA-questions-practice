class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n);
        vector<int> frequency(n + 1, 0);
        int common = 0;

        for (int i = 0; i < n; ++i) {
            frequency[A[i]]++;
            if (frequency[A[i]] == 2) {
                common++;
            }

            frequency[B[i]]++;
            if (frequency[B[i]] == 2) {
                common++;
            }

            C[i] = common;
        }

        return C;
    }
};