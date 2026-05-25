class Solution {
public:
    bool is_palindrome(string& str) {
        int right = str.size()-1;
        int left  = 0;
        while(left < right) {
            if(str[left++] != str[right--]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> splits;
        get_splits(s, result, splits, 0);
        return result;
    }
    void get_splits(string& s, vector<vector<string>>& result, vector<string>& splits, int index) {
        if(index >= s.size()) {
            result.push_back(splits);
            return;
        }
        string split;
        for(int i=index; i < s.size(); ++i) {
            split += s[i];
            // cout<< split << endl;
            if(is_palindrome(split)) {
                splits.push_back(split);
                get_splits(s, result, splits, i+1);
                splits.pop_back();
            }
        }
    }
};
