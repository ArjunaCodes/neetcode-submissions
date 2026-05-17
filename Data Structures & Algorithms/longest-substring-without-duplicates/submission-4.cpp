class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int start = 0; 
        int end   = 1;
        hash.insert(s[0]);
        int size = s.size();
        if(size<1) return 0;
        int max_len = 1;
        for(end; end<size; ++end) {
            if(hash.find(s[end]) == hash.end()) {
                max_len = max(end-start+1, max_len);
                hash.insert(s[end]);
            }
            else {
                while(hash.find(s[end]) != hash.end()) {
                    hash.erase(s[start++]);
                }
                max_len = max(end-start+1, max_len);
                hash.insert(s[end]);
            }
        }
        return max_len;
    }
};
