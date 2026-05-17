class Solution {
public:
    void back_track(vector<vector<int>>&subsets, vector<int>&nums, vector<int>set, int index) {
        if(index >= nums.size()) return;
        // subsets.push_back(set);
        set.push_back(nums[index]);
        subsets.push_back(set);
        back_track(subsets, nums, set, index+1);
        set.pop_back();
        back_track(subsets, nums, set, index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        back_track(subsets, nums, {}, 0);
        subsets.push_back({});
        return subsets;
    }
};
