class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values;
        unordered_set<string> token{"+", "-", "*", "/"};
        int ans{-1};
        for(auto& str: tokens) {
            if(token.find(str) != token.end()) {
                int second = values.top();
                values.pop();
                int first = values.top();
                values.pop();
                if("+" == str) {
                    ans = first + second;
                }
                if("-" == str) {
                    ans = first - second;
                }
                if("*" == str) {
                    ans = first * second;
                }
                if("/" == str) {
                    ans = first / second;
                }
                values.push(ans);
                continue;
            }
            values.push(stoi(str));
        }
        if(not values.empty()) {
            ans = values.top();
        }
        return ans;
    }
};
