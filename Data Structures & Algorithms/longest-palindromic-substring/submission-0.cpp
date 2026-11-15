class Solution {
public:
    bool is_palindrome(string& s) {
        
    }
    string longestPalindrome(string s) {
        int str_size = s.size();
        string res;
        unsigned int res_len{0};
        for(int i =0; i < str_size; ++i) {
            int k, l;
            k = i; l = i;
            while(k>=0 and l<str_size and s[k] == s[l]){
                if(res_len < (l-k+1)) {
                    res_len = l-k+1;
                    res = s.substr(k, res_len);
                }
                k--;
                l++;
            }
            k = i; l = i+1;
            while(k>=0 and l<str_size and s[k] == s[l]) {
                if(res_len < (l-k+1)) {
                    res_len = l-k+1;
                    res = s.substr(k, res_len);
                }
                k--;
                l++;
            }
        }
        return res;

    }
};
