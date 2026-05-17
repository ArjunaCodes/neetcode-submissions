class Solution {
public:
    int find_target_index(vector<int>& nums, int target, int left, int right) {
        while(left <= right) {
            int mid = left + (right - left) / 2;
            std::cout<< mid << " " << left << " " << right << endl;
            if(target > nums[mid]) {
                left = mid + 1;
            } 
            else if(target < nums[mid]) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int right = nums.size()-1, left = 0;
        int mid = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] >= nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        if(mid == 0) {
            return find_target_index(nums, target, mid, nums.size()-1);
        }
        else if (target <= nums[mid-1] and target >= nums[0]) {
            std::cout<<mid<< endl;
            return find_target_index(nums, target, 0, mid-1);
        }
        return find_target_index(nums, target, mid, nums.size()-1);
        
    }
};
