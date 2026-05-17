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
        string copy = copy_s;
        reverse(copy_s.begin(), copy_s.end());
        // std::cout<< copy_s << endl;
        // std::cout<< copy << endl;
        return copy_s == copy;
    }
};
