class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        for(int i=0; i<size; ++i) {
            if(nums[abs(nums[i])] < 0) return abs(nums[i]);
            nums[abs(nums[i])] = -nums[abs(nums[i])];
        }
        return -1;
    }
};
