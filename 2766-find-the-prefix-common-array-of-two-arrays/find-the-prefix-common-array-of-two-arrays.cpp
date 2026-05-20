class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n);
        long long seen = 0;
        int common = 0;

        for (int i = 0; i < n; ++i) {
            if ((seen >> A[i]) & 1) {
                common++;
            } else {
                seen |= (1LL << A[i]);
            }

            if ((seen >> B[i]) & 1) {
                common++;
            } else {
                seen |= (1LL << B[i]);
            }

            C[i] = common;
        }

        return C;
    }
};