class Solution {
public:
    vector<vector<int>> find_pair(vector<int>& nums, int start, int target) {
        unordered_map<int, int> compute;
        vector<vector<int>> ans;
        for(int i=start; i < nums.size(); ++i) {
            if(compute.count(target - nums[i])) {
                ans.push_back({nums[compute[target - nums[i]]], nums[i]});
            }
            compute[nums[i]] = i;
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<string> duplicate;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); ++i) {
            vector<vector<int>> pairs = find_pair(nums, i+1, -(nums[i]));
            if(not pairs.empty()){
                for(auto& pair: pairs) {
                    pair.emplace_back(nums[i]);
                    sort(pair.begin(), pair.end());
                    string hash {to_string(pair[0]) + to_string(pair[1]) + to_string(pair[2])};
                    if(duplicate.find(hash) == duplicate.end()) {
                        ans.emplace_back(pair);
                        // std::cout<<"not duplicate " << hash << endl;
                        duplicate.insert(hash);
                    } 
                }
            }
        }
        return ans;
    }
};

// -4 -1 -1 0 1 2