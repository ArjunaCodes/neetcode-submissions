class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string ans;
        generate(n, 0, 0, result, ans);
        return result;
    }
    void generate(int n, int open, int close, vector<string>& res, string formed) {
        if(open == n and close == n) {
            res.push_back(formed);
            return;
        }
        if(open < n){
            formed += "(";
            generate(n, open+1, close, res, formed);
            formed.pop_back();
        }
        if(open > close)
            generate(n, open, close+1, res, formed += ")");
    }
};
