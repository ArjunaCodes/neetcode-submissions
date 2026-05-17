class Solution {
public:
    bool isPalindrome(string s) {
        std::transform(s.begin(), s.end(), s.begin(), [](auto ch){
            return std::tolower(ch);
        });
        string copy_s;
        for(auto ch: s){
            if(isalpha(ch) or isdigit(ch)){
                copy_s += ch;
            }
        }
        int start = 0;
        int end = copy_s.size() - 1;
        while(start < end) {
            if(copy_s[start] != copy_s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
