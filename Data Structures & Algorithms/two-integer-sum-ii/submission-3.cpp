class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end   = numbers.size()-1;
        while(start < end) {
            int sum_of_two =  numbers[start] + numbers[end];
            if(sum_of_two == target) {
                return {start+1, end+1};
            }
            else if(sum_of_two > target) {
                --end;
            }
            else {
                start++;
            }
        }
        return {start+1, end+1};
    }
};
