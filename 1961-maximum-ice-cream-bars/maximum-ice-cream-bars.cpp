class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) {
        int freq[100001] = {0};
        int max_cost = 0;

        for (int cost : costs) {
            freq[cost]++;
            if (cost > max_cost) {
                max_cost = cost;
            }
        }

        int ice_cream_count = 0;

        for (int price = 1; price <= max_cost; ++price) {
            if (freq[price] == 0) continue;

            long long total_cost_for_all = (long long)price * freq[price];

            if (coins >= total_cost_for_all) {
                coins -= total_cost_for_all;
                ice_cream_count += freq[price];
            } else {
                ice_cream_count += coins / price;
                break;
            }
        }

        return ice_cream_count;
    }
};