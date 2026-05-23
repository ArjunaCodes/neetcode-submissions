class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> res;
        find_combination(nums, result, res, target);
        return result;
    }
    void find_combination(vector<int>& nums, vector<vector<int>>& results, vector<int>& res, int target, int index=0) 
    {
        if(target == 0){
            results.push_back(res);
            return;
        }
        if(index >= nums.size() or target < 0) return;
        res.push_back(nums[index]);
        find_combination(nums, results, res, target - nums[index], index);
        // find_combination(nums, results, res, target - nums[index], index+1);
        res.pop_back();
        find_combination(nums, results, res, target, index+1);
    }
};
