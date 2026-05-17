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
    int value;
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder_traversal(root, k);
        return value;
    }
    int inorder_traversal(TreeNode* root, int& k) {
        if(not root) return value;
        inorder_traversal(root->left, k);
        --k;
        if(not k)
           return value = root->val;
        return inorder_traversal(root->right, k);
    }
};
