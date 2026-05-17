class Solution {
public:
    int findMin(vector<int> &nums) {
        int min_value;
        int size = nums.size();
        if(nums[0] < nums[size-1]) {
            return nums[0];
        }
        int left = 0, right = size-1;
        min_value = nums[right];
        while(left <= right) {
            int mid = left + ((right - left) / 2);
            std::cout<<left << " " << right <<endl;
            if(mid>0 and mid < size and nums[mid-1] > nums[mid] and nums[mid+1] > nums[mid]) {
                min_value = nums[mid];
                break;
            }
            else if (nums[mid] > nums[size-1]) {
                left = mid + 1;
            }
            else {
                right = mid -1;
            }
        }
        return min_value;
    }
};
