class Solution: public iostream {
public:
    void find_combination(vector<int>& nums, vector<vector<int>>& comb, vector<int> target_num, int target, int index) {
        int sum = accumulate(target_num.begin(), target_num.end(), 0);
        // for(auto& a: target_num) {
        //     std::cout<<a<<" ";
        // }
        // std::cout<<endl;
        if(sum > target or index >= nums.size()) return;
        if(sum == target) {
            comb.push_back(target_num);
            return;
        }
        target_num.push_back(nums[index]);
        find_combination(nums, comb, target_num, target, index);
        target_num.pop_back();
        find_combination(nums, comb, target_num, target, index + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        find_combination(nums, ans, {}, target, 0);
        return ans;
    }
};
