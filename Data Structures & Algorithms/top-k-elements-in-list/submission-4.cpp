class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        int size = nums.size();
        for(auto num: nums) {
            counter[num] += 1;
        }
        vector<vector<int>> repeat_tracker(nums.size()+1);
        for(const auto& [num, count]: counter) {
            repeat_tracker[count].push_back(num);
        }
        vector<int> ans;
        for(int i=size; i > 0; --i) {
            for (int n: repeat_tracker[i]){
                ans.push_back(n);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
