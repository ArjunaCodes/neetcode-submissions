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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder_traversal(root, ans);
        return ans[k-1];
    }
    void inorder_traversal(TreeNode* root, vector<int>& ans) {
        if(not root) return;
        inorder_traversal(root->left, ans);
        ans.push_back(root->val);
        inorder_traversal(root->right, ans);
        
    }
};
