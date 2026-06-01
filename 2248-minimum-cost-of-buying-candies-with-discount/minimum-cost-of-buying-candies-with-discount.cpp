class Solution {
public:
    int minimumCost(std::vector<int>& cost) {
        // Sort the costs in descending order
        std::sort(cost.begin(), cost.end(), std::greater<int>());
        
        int totalCost = 0;
        
        // Loop through the sorted candies
        for (int i = 0; i < cost.size(); ++i) {
            // Every 3rd candy (index 2, 5, 8...) is free, so we skip it
            if ((i + 1) % 3 == 0) {
                continue;
            }
            totalCost += cost[i];
        }
        
        return totalCost;
    }
};