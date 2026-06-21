class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) {
        int max_cost = 0;
        for (int cost : costs) {
            max_cost = std::max(max_cost, cost);
        }

        std::vector<int> freq(max_cost + 1, 0);
        for (int cost : costs) {
            freq[cost]++;
        }

        int ice_cream_count = 0;

        for (int price = 1; price <= max_cost; ++price) {
            if (freq[price] == 0) continue;

            long long total_cost_for_all = (long long)price * freq[price];

            if (coins >= total_cost_for_all) {
                coins -= total_cost_for_all;
                ice_cream_count += freq[price];
            } else {
                int count_to_buy = coins / price;
                ice_cream_count += count_to_buy;
                break;
            }
        }

        return ice_cream_count;
    }
};