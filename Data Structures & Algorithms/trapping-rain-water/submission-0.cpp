class Solution {
public:
    int trap(vector<int>& height) {
        int rain_water {0};
        int size = height.size();
        vector<int> pre(size, 0);
        vector<int> post(size, 0);
        pre[0] = height[0];
        post[size-1] = height[size-1];
        for(int i=1; i<size; ++i) {
            pre[i] = max(pre[i-1], height[i]);
        }
        for(int i=size-2; i>=0; --i) {
            post[i] = max(post[i+1], height[i]);
        }
        for(int i=1; i<size-1; ++i) {
            int space = min(pre[i], post[i]);
            // std::cout<< pre[i] << " " << post[i] << endl;
            // std::cout<<"index " << i << " " << (space - height[i]) << " space " << space << endl;
            rain_water += (space - height[i]);
        }
        return rain_water;
    }
};
