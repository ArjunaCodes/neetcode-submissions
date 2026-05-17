class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if(size < 1) return 0;
        sort(nums.begin(), nums.end());
        int max_start{0}, max_end{1};
        int temp_start{0}, temp_end{1};
        int max_size = 1;
        int temp_size = 1;
        for(int i=1; i < size; ++i) {
            if(nums[i-1] == nums[i]) continue;
            if(nums[i-1]+1 == nums[i]){
                temp_end = i;
                temp_size++;
                // std::cout<<temp_size << ":" << nums[i]<< "  ";
                continue;
            } 
            if(temp_size > max_size) {
                max_size = temp_size;
            }
            temp_size = 1;
        }
        return max(temp_size, max_size);
    }
};
// nums=[9,1,-3,2,4,8,3,-1,6,-2,-4,7]
// -4 -3 -2 -1 1 2 3 4 6 7 8 9
