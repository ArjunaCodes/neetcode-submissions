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
    int value {INT_MIN};
    int kthSmallest(TreeNode* root, int& k) {
        if(not root) return value;
        kthSmallest(root->left, k);
        if(value != INT_MIN) return value;
        --k;
        if(not k) return value = root->val;
        kthSmallest(root->right, k);
        return value;
    }
};
