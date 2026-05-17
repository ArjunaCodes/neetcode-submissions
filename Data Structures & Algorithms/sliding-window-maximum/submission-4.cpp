class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int, greater<int>> max_heap;
        int left = 0, right = 0;
        int size = nums.size();
        vector<int> ans;
        while(right < size) {
            max_heap[nums[right]] = right;
            if((right - left + 1) == k) {
                ans.emplace_back(max_heap.begin()->first);
                ++left;
            }
            while(not max_heap.empty() and max_heap.begin()->second < left) {
                max_heap.erase(max_heap.begin());
            }
            ++right;
        }
        return ans;
    }
};
