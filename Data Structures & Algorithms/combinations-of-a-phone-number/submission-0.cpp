class Solution {
public:
    unordered_map<char, vector<char>> num_char {{'1', {}}
    , {'2',{'a', 'b', 'c'}}
    , {'3',{'d', 'e', 'f'}}
    , {'4',{'g', 'h', 'i'}}
    , {'5',{'j', 'k', 'l'}}
    , {'6',{'m', 'n', 'o'}}
    , {'7',{'p', 'q', 'r', 's'}}
    , {'8',{'t', 'u', 'v'}}
    , {'9',{'w', 'x', 'y', 'z'}}};
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
        for(char ch: num_char[digit[index]]){
            combine(result, digit, index+1, str+ch);
        }
    }
};
