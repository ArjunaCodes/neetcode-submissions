class Solution {
public:
    // int min_cost(vector<int>& cost, int index) {
    //     if(cost.size() <= index) return 0;
    //     return min(min_cost(cost, index+1) + cost[index], min_cost(cost, index+2) + cost[index]);
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        int size = cost.size();
        for(int i=2; i <= size; ++i) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return dp[size];
    }
};
