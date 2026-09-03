class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mnOdd = INT_MAX;
        int mnEven = INT_MAX;

        for (int x : nums1) {
            if (x & 1)
                mnOdd = min(mnOdd, x);
            else
                mnEven = min(mnEven, x);
        }

        if (mnOdd == INT_MAX || mnEven == INT_MAX)
            return true;

        return mnOdd < mnEven;
    }
};