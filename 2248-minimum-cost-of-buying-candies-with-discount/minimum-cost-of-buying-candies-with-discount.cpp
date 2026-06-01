class Solution {
public:
    int minimumCost(std::vector<int>& cost) {
        std::sort(cost.begin(), cost.end(), std::greater<int>());
        
        int totalCost = 0;
        
        for (int i = 0; i < cost.size(); ++i) {
            if ((i + 1) % 3 == 0) {
                continue;
            }
            totalCost += cost[i];
        }
        
        return totalCost;
    }
};