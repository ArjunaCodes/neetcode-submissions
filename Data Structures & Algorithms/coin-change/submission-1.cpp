class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> vec(amount+1, INT_MAX);
        vec[0] = 0;
        for(int i=1; i<=amount; ++i) {
            for(int j=0; j<coins.size(); ++j) {
                int coin = coins[j];
                int amnt = i;
                if(coin <= amnt) {
                    amnt -= coin;
                    if(amnt <= i and vec[amnt] != INT_MAX){
                        vec[i] = min(vec[i], vec[amnt] + 1);
                    }
                }
            }
        }
        // cout<<INT_MAX << endl;
        return vec[amount] == INT_MAX ? -1 : vec[amount];
    }
};
// 1 2 3 4 5 6 7 8 9 10 11 12
// 1 2 3 4 1 2 3 4 5 1  2   