class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_size = s1.size();
        int s2_size = s2.size();
        if(s1_size > s2_size) return false;
        int l=0;
        int r=0;
        unordered_map<char, int> sa;
        unordered_map<char, int> sb;
        for(auto s: s1) {
            sa[s]++;
        }
        auto print = [](auto &st ) {
            for(auto a: st) {
                std::cout<< a.first << " ";
            }
            cout<< std::endl;
        };
        while(r < s2_size) {
            sb[s2[r]]++;
            if((r-l+1) == s1_size) {
               print(sa);
               print(sb);
               if(sa == sb) return true;
               sb[s2[l]]--;
               if(sb[s2[l]] == 0) {
                    sb.erase(s2[l]);
               }
               l++;
            }
            // else if((r-l+1) > s1_size) {
            //     sb.erase(s2[l]);
            //     l++;
            // }
            r++;
        }

        return sa == sb;
    }
};
