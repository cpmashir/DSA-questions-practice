class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // Fast I/O to maximize memory and runtime scores
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int max_alt = 0;
        int current_alt = 0;
        
        for (int g : gain) {
            current_alt += g;
            if (current_alt > max_alt) {
                max_alt = current_alt;
            }
        }
        
        return max_alt;
    }
};