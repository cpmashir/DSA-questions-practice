class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;
        int diff = 0, q1 = 0, q2 = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                q1++;
            else
                diff += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                q2++;
            else
                diff -= num[i] - '0';
        }

        if ((q1 + q2) % 2)
            return true;

        return diff != 9 * (q2 - q1) / 2;
    }
};