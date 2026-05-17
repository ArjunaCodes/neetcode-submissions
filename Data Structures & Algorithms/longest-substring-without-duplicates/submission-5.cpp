class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int start = 0; 
        int end   = 1;
        hash.insert({s[0], 0});
        int size = s.size();
        if(size<1) return 0;
        int max_len = 1;
        for(end; end<size; ++end) {
            if(hash.find(s[end]) != hash.end()) {
                start = max(hash[s[end]]+1, start);
            }
            hash[s[end]] = end;
            max_len = max(max_len, end - start + 1);
            
        }
        return max_len;
    }
};
