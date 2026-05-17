class Solution {
public:
    bool is_anagram(string a, string b){
        if(a.size() != b.size()) return false;
        if(a == b) return true;
        sort(b.begin(), b.end());
        return a == b;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size(); 
        if(size <= 1) return {strs};
        vector<vector<string>> ans;
        vector<bool> tracker(size, false);
        for(int i=0; i < size; ++i) {
            vector<string> sub;
            if(tracker[i] == false) {
                tracker[i] = true;
                sub.push_back(strs[i]);
                for (int j=i+1; j<size; ++j) {
                    if(tracker[j] == false) {
                        string first = strs[i];
                        sort(first.begin(), first.end());
                        if(is_anagram(first, strs[j])) {
                            sub.push_back(strs[j]);
                            tracker[j] = true;
                        }
                    }   
                }
                ans.push_back(sub);
            }
        }
        return ans;
    }
};
