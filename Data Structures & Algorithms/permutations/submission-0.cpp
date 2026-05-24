class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int> nums, int idx) {
        if (idx == nums.size()) {
            // cout<< " considered " <<endl;
            // print_state(nums);
            res.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            // cout<<" i " << i << " idx " << idx << " ";
            // print_state(nums);
            backtrack(nums, idx + 1);
            // cout<<endl;
            // swap(nums[idx], nums[i]);
        }
    }
    void print_state(vector<int>& nums) {
        cout<< "[" ;
        for(auto num: nums) {
            cout<< num <<",";
        }
        cout<<"]";
    }
};