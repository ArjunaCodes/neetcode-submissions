class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        combi(candidates, result, res, target, 0);
        return result;
    }
    void combi(vector<int>& candidates, vector<vector<int>>& result, vector<int>& res, int target, int index) {
        if(target == 0) {
            result.push_back(res);
            return;
        }
        if(index >= candidates.size() or target < 0) return;
        res.push_back(candidates[index]);
        combi(candidates, result, res, target - candidates[index], index+1);
        res.pop_back();
        while(index + 1 < candidates.size() and candidates[index] == candidates[index+1]){
            ++index;
        }
        combi(candidates, result, res, target, index+1);
        return;
    }
};
