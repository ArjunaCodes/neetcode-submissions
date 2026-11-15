class Solution {
public:
    int countSubstrings(string s) {
        int s_size = s.size();
        int result {0};
        for(int i=0; i<s_size; ++i) {
            int k, l;
            k = i , l = i;
            while(k>=0 and l<s_size and s[k] == s[l]) {
                result++;
                k--; 
                l++;
            }
            k = i; l = i+1;
            while(k>=0 and l<s_size and s[k] == s[l]) {
                result++;
                k--;
                l++;
            }
        }
        return result;
    }
};
