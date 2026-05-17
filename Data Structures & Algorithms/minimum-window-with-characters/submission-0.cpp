class Solution {
public:
    string minWindow(string s, string t) {
        int size_1 = s.size();
        int size_2 = t.size();
        if(size_2 > size_1) return "";
        unordered_map<char, int> target;
        unordered_map<char, int> current;
        for(auto& ch: t) {
            target[ch]++;
        }
        int l = 0, r = 0;
        int required = target.size();
        int formed = 0;
        int minLen = INT_MAX;
        int startIdx = 0;
        for(r = 0; r < size_1; ++r) {
            if(target.find(s[r]) != target.end()) {
                current[s[r]]++;
                if(current[s[r]] == target[s[r]]) formed++;
            }
            // cout<< formed << " " << required << endl;
            while(formed == required) {
                if((r - l + 1 ) < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }
                // std::cout<<"ENTERED";
                if(target.find(s[l]) != target.end()) {
                    if(current[s[l]] == target[s[l]]) formed--;
                    current[s[l]]--;
                }
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
