class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // hello world 
        int size = nums.size();
        vector<int> pre(size);
        vector<int> post(size);
        pre[0] = nums[0];
        post[size-1] = nums[size-1];
        for(int i=1; i<size; ++i) {
            pre[i] = pre[i-1] * nums[i];
            // std::cout<< " i : " << i << " " << pre[i] <<"  " << endl;
        }
        for(int i=size-2; i>=0; --i) {
            post[i] = post[i+1] * nums[i];
        }
        vector<int>ans(size);
        for(int i=1; i<size-1; ++i) {
            ans[i] = pre[i-1] * post[i+1];
            // std::cout<< " i : " << i << " " << ans[i] <<"  " << endl;
        }
        ans[0] = post[1];
        ans[size-1] = pre[size-2];
        return ans;
    }
};
