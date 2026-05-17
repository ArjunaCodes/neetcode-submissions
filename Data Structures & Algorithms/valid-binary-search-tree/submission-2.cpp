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
    bool isValidBST(TreeNode* root) {
        if(not root) return true;
        return check_for_valid(root, INT_MAX, INT_MIN);
    }
    bool check_for_valid(TreeNode* root, int max_n, int min_n) {
        if(not root) return true;
        if((min_n != INT_MIN and root->val <= min_n) or (max_n != INT_MAX and root->val >= max_n)) {
            // cout<< root->val << " min_n " << min_n << " max_n " << max_n << endl;
            return false;
        } 
        return check_for_valid(root->left, min(max_n, root->val), min_n) and check_for_valid(root->right, max_n, max(min_n, root->val));
    }
};
