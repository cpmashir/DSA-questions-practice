class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDistance = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                // Calculate the absolute difference between indices
                int absDiff = abs(i - startIndex);
                
                // Compare the direct distance vs the circular wrap-around distance
                int currentDistance = min(absDiff, n - absDiff);
                
                // Update the global minimum
                minDistance = min(minDistance, currentDistance);
            }
        }

        // If minDistance was never updated, the target wasn't found
        return (minDistance == INT_MAX) ? -1 : minDistance;
    }
};