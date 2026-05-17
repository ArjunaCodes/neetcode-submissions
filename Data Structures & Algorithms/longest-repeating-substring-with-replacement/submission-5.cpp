class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int max_count{0};
        int left = 0;
        int right = 0;
        int size  = s.size();
        int max_freq{0};
        while(right < size) {
            freq[s[right]]++;
            max_freq = max(freq[s[right]], max_freq);
            while((right - left) + 1 - max_freq > k) {
                freq[s[left]]--;
                left++;
            }
            max_count = max(max_count, right - left + 1);
            right++;
        }
        return max_count;
    }
};
