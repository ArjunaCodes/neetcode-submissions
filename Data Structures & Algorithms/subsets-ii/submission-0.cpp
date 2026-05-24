class Solution {
public:
    set<vector<int>> sets;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        get_subsets(nums, {}, 0);
        return {sets.begin(), sets.end()};
    }
    void get_subsets(vector<int>& nums, vector<int> subset, int index) {
        if(index == nums.size()){
            sets.insert(subset);
            return;
        }
        subset.push_back(nums[index]);
        get_subsets(nums, subset, index+1);
        subset.pop_back();
        get_subsets(nums, subset, index+1);
    }
};
