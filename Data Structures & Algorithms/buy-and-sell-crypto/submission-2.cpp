class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought = prices[0];
        int size = prices.size();
        int profit = 0;
        for(int i=1; i<size; ++i) {
            profit = max(prices[i] - bought, profit);
            bought = min(bought, prices[i]);
        }
        return profit;
    }
};
