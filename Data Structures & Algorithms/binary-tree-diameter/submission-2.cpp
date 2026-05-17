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
    int max_path = 0;
    int find(TreeNode* root) {
        if(not root) return 0;
        int right_nodes = find(root->right);
        int left_nodes  = find(root->left);
        max_path = max(right_nodes+left_nodes, max_path);
        return max(right_nodes, left_nodes) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (not root) return 0;
        find(root);
        return max_path;
    }
};
