class Solution {
public:

    string encode(vector<string>& strs) {
        int len = strs.size();
        string encoded;
        encoded += std::to_string(len) + '\0';
        for(const auto& str: strs) {
            encoded += str + '\0';
        }
        return encoded;
    }

    vector<string> decode(string s) {
        string get_size;
        int index = 0;
        for(; ; index++) {
            if(s[index] == '\0') break;
            get_size += s[index];
        }
        int size {stoi(get_size)};
        vector<string> decoded;
        int str_len = s.size();
        string splitter{""};
        ++index;
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
