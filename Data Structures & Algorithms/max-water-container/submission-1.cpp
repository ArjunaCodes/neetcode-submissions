class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_ans {INT_MIN};
        int size = heights.size();
        int start =0; 
        int end = size-1;
        while(start < end){
            max_ans = max((end-start) * min(heights[start], heights[end]), max_ans);
            if(heights[start] < heights[end]) {
                start++;
            }
            else if(heights[start] > heights[end]) {
                end--;
            }
            else {
                start ++;
                end --;
            }
        }
        return max_ans;
    }
};
// 1 7 2 5 4 7 3 6
// 1 7 7 7 7 7 7 7
// 7 7 7 7 7 7 6 6