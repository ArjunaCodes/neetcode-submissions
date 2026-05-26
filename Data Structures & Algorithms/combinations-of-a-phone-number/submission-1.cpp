class Solution {
public:
    vector<string> num_char {"", ""
    , "abc"
    , "def"
    , "ghi"
    , "jkl"
    , "mno"
    , "pqrs"
    , "tuv"
    , "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() < 1) return result;
        combine(result, digits, 0, "");
        return result;
    }
    void combine(vector<string>& result, string& digit, int index, string str) {
        if(index >= digit.size()) {
            result.emplace_back(str);
            return;
        }
        for(char ch: num_char[digit[index] - '0']){
            combine(result, digit, index+1, str+ch);
        }
    }
};
