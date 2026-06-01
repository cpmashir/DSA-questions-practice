class Solution {
public:
    int minimumCost(std::vector<int>& cost) {
        int counts[101] = {0};
        for (int c : cost) {
            counts[c]++;
        }

        int totalCost = 0;
        int candyCount = 0;

        for (int price = 100; price >= 1; --price) {
            while (counts[price] > 0) {
                candyCount++;
                if (candyCount % 3 != 0) {
                    totalCost += price;
                }
                counts[price]--;
            }
        }

        return totalCost;
    }
};