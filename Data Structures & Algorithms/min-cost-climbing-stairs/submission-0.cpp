class Solution {
public:
    int min_cost(vector<int>& cost, int index) {
        if(cost.size() <= index) return 0;
        return min(min_cost(cost, index+1) + cost[index], min_cost(cost, index+2) + cost[index]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(min_cost(cost, 0), min_cost(cost, 1));
    }
};
