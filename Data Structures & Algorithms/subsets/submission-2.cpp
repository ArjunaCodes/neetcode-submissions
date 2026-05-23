class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums){
        sets(nums,{}, 0);
        ans.push_back({});
        return ans;
    }
    void sets(vector<int>& nums, vector<int> arr, int index = 0) {
        if(index >= nums.size()) return;
        arr.push_back(nums[index]);
        ans.push_back(arr);
        sets(nums, arr, index+1);
        arr.pop_back();
        sets(nums, arr, index+1);
        return;
    }
};
