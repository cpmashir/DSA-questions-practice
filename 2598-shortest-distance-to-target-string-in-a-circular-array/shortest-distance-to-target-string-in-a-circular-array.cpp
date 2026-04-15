class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDistance = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int absDiff = abs(i - startIndex);
                int currentDistance = min(absDiff, n - absDiff);
                minDistance = min(minDistance, currentDistance);
            }
        }

        return (minDistance == INT_MAX) ? -1 : minDistance;
    }
};