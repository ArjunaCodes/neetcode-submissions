class Solution {
public:
    int numDecodings(string s) {
        int s_size = s.size();
        vector<int> dp(s_size + 2, 0);
        dp[s_size] = 1;
        dp[s_size - 1] = s[s_size-1] != '0' ? 1 : 0;
        for(int i = s_size-1; i >=0 ; --i) {
            if(s[i] == '0') {
                dp[i] = 0;
            }
            else if(s[i] == '1' or (s[i] == '2' and (s[i+1] - '0') < 7 )) {
                dp[i] = dp[i+1] + dp[i+2];
            }
            else {
                dp[i] = dp[i+1];
            }
        }
        return dp[0];
    }
};
// 
// 10122334
// 2 1 1 2
// 2 11 2
// 2 1 12
// 21 1 2
// 21 12
