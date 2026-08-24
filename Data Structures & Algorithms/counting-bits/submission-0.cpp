class Solution {
public:
    unsigned int get_bit_count(int n) {
        return __builtin_popcount(n);
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; ++i) {
            ans.push_back(get_bit_count(i));
        }
        return ans;
    }
};
