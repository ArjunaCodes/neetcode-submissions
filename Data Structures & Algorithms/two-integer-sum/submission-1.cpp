class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int, int> p_map;
        for(int i=0; i<size; ++i) {
            int diff = target - nums[i];
            if (p_map.find(diff) != p_map.end()) {
                return {p_map[diff], i};
            }
            p_map.insert({nums[i], i});
        }
        return {};
    }
};
