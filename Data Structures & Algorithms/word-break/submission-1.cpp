class Solution {
public:
    bool is_possible(const string& s, int start, unordered_set<string>& dict, vector<int>& memo) {
        // Base case: If we reach the end of the string, segmentation is successful
        if (start == s.size()) return true;
        
        // If we have already calculated the result for this start index, return it
        // 0 means unvisited, 1 means false, 2 means true
        if (memo[start] != 0) {
            return memo[start] == 2;
        }
        
        // Try every possible substring starting from 'start' to the end of the string
        for (int end = start; end < s.size(); end++) {
            string sub_str = s.substr(start, end - start + 1);
            
            // If the current substring is in the dictionary
            if (dict.find(sub_str) != dict.end()) {
                // Recursively check if the rest of the string can be segmented
                if (is_possible(s, end + 1, dict, memo)) {
                    memo[start] = 2; // Mark as true
                    return true;
                }
            }
        }
        
        memo[start] = 1; // Mark as false so we never re-evaluate this start index
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        // State array: 0 = unvisited, 1 = false, 2 = true
        vector<int> memo(s.size(), 0); 
        
        return is_possible(s, 0, dict, memo);
    }
};