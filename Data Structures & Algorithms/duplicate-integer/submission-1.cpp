class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> hash;
        for(const auto& num: nums) {
            if(hash.find(num) != hash.end()){
                return true;
            }
            hash.insert(num);
        }
        return false;
    }
};