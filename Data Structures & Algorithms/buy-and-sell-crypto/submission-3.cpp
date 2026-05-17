class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought = prices[0];
        int size = prices.size();
        int profit = 0;
        for(const auto& price: prices) {
            profit = max(price - bought, profit);
            bought = min(bought, price);
        }
        return profit;
    }
};
