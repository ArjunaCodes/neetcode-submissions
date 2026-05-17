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
    bool isBalanced(TreeNode* root) {
        return counter_balance(root) != -1;
    }
    int counter_balance(TreeNode* root) {
        if(not root) return 0;
        int right_sub = counter_balance(root->right);
        int left_sub  = counter_balance(root->left);
        if(right_sub == -1 or left_sub == -1) return -1;
        if(abs(right_sub - left_sub) > 1) return -1;
        return max(right_sub, left_sub) + 1;
    }
};
