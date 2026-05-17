/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(not root) return ans;
        queue<TreeNode*> que;
        que.push(root);
        while(not que.empty()) {
            int size = que.size();
            TreeNode* node = que.front();
            ans.push_back(node->val);
            while(size--) {
                node = que.front();
                que.pop();
                if(node->right) {
                    que.push(node->right);
                }
                if(node->left) {
                    que.push(node->left);
                }
            }
        }
        return ans;
    }
};
