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
    bool isSame(TreeNode* root, TreeNode* another) {
        if(not root and not another) return true;
        if((root and not another) or (not root and another)) return false;
        if(root->val != another->val) return false;
        return isSame(root->left, another->left) and isSame(root->right, another->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(not root and not subRoot) return true;
        if(not root) return false;
        if(root->val == subRoot->val) 
            if(isSame(root, subRoot)) {
                return true;
            } 
        bool is_same = isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
        if(is_same) return true;
        return false;
    }
};
