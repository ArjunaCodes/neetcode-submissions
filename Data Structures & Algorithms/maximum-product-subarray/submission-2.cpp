class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n_size = nums.size();
        vector<int> dp(n_size+1, INT_MIN);
        dp[0] = nums[0];
        int prev_max {nums[0]};
        int prev_min {nums[0]};
        int max_  {nums[0]};
        for(int i=1; i<n_size; ++i) {
            int curr = nums[i];
            int temp_max = max({curr, curr*prev_max, curr* prev_min});
            int temp_min = min({curr, curr*prev_max, curr*prev_min});
            prev_max = max({temp_max, curr, temp_min});
            max_ = max(prev_max, max_);
            prev_min = min({temp_min, curr, temp_max});
        }
        return max_;
    }
};
