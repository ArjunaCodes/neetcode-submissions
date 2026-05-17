class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(const auto& str: strs) {
            encoded += str + '\0';
        }
        return encoded;
    }

    vector<string> decode(string s) {
        int index = 0;
        vector<string> decoded;
        int str_len = s.size();
        string splitter{""};
        for(; index < str_len; ++index) {
            if(s[index] == '\0') {
                decoded.emplace_back(splitter);
                splitter = "";
                continue;
            }
            splitter += s[index];
        }
        return decoded;
    }
};
