class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // Frequency array for all 26 lowercase English letters
        int counts[26] = {0};
        for (char c : text) {
            counts[c - 'a']++;
        }
        
        // Extract the counts for the specific characters in "balloon"
        int b = counts['b' - 'a'];
        int a = counts['a' - 'a'];
        int l = counts['l' - 'a'] / 2; // Requires 2 'l's per word
        int o = counts['o' - 'a'] / 2; // Requires 2 'o's per word
        int n = counts['n' - 'a'];
        
        // The limiting factor determines the maximum number of words
        return min({b, a, l, o, n});
    }
};