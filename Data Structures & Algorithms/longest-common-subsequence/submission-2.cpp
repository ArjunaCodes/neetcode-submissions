class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1 == text2) return text1.size();
        int size_1 = text1.size();
        int size_2 = text2.size();
        vector<vector<int>> dp(size_1+1, vector<int>(size_2+1, 0));
        for(int i=0; i<size_1; ++i) {
            for(int j=0; j<size_2; ++j) {
                dp[i+1][j+1] = max(dp[i + 1][j], dp[i][j+1]);
                if(text1[i] == text2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1; 
                }
                // std::cout<<dp[i+1][j+1]<<" ";
            }
            // std::cout<<endl;
        }
        return dp[size_1][size_2];
    }
};
