class Solution {
public:
    void combination(const vector<int>& candidates, vector<vector<int>>& sum, vector<int> curr, int index, int target) {
        if(target == 0){
            sum.push_back(curr);
            return;
        } 
        if(index == candidates.size() or target < 0) return;
        target -= candidates[index];
        curr.emplace_back(candidates[index]);
        combination(candidates, sum, curr, index + 1, target);
        target += candidates[index];
        curr.pop_back();
        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index++;
        }
        combination(candidates, sum, curr, index + 1, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sum;
        sort(candidates.begin(), candidates.end());
        combination(candidates, sum, {}, 0, target);
        return sum;
    }
};
