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
    int goodNodes(TreeNode* root) {
        if(not root) return 0;
        vector<int> ans;
        ans.push_back(root->val);
        find_greater_so_far(root->right, ans, root->val);
        find_greater_so_far(root->left, ans, root->val);
        return ans.size();
    }
    void find_greater_so_far(TreeNode* root, vector<int>& ans, int val) {
        if(not root) return;
        if(root->val >= val) ans.push_back(root->val);
        find_greater_so_far(root->right, ans, max(val, root->val));
        find_greater_so_far(root->left, ans, max(val, root->val)); 
    }
};
