class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> closing{{')', '('}, {']', '['}, {'}', '{'}};
        for(const auto& ch: s) {
            if(closing.find(ch) != closing.end()) {
                if(st.empty() or st.top() != closing[ch]) return false;
                st.pop();
             }
            else
                st.push(ch);
        }
        return st.empty();
    }
};
