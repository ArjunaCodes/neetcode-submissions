class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size_1 = nums1.size();
        int size_2 = nums2.size();
        vector<int> merge(nums1.begin(), nums1.end());
        merge.insert(merge.begin(), nums2.begin(), nums2.end());
        sort(merge.begin(), merge.end());
        if((size_1 + size_2) % 2) {
            return merge[merge.size()/2];
        }
        return float(merge[(merge.size())/2] + merge[merge.size()/2 - 1])/2;
    }
};
