class Solution {
public:
    int max_rob_ammount(vector<int>& nums, int index){
        if(nums.size() <= index) {
            return 0;
        }
        return max(max_rob_ammount(nums, index+2) + nums[index], max_rob_ammount(nums, index+3) + nums[index]);
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 0);
        if(size < 4) return max({nums[0], nums[1], nums[2]+nums[0]});

        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2] + nums[0];
        for(int i=2; i< size; ++i) {
            dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
        }
        return max(dp[size-1], dp[size-2]);
    }
};
