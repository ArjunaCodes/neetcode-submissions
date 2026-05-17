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
    int pre_index = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if(l > r) return nullptr;
        auto root = new TreeNode (preorder[pre_index]);
        int mid = find(inorder.begin(), inorder.end(), preorder[pre_index++]) - inorder.begin();
        root->left = build(preorder, inorder, l, mid-1);
        root->right = build(preorder, inorder, mid+1, r);
        return root;
    }
};
