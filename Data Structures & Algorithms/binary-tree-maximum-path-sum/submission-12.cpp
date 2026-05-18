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
    int max_path_sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        find_max_sum(root);
        return max_path_sum;
    }
    int find_max_sum(TreeNode* root) {
        if(not root) return 0;
        int left = find_max_sum(root->left);
        int right = find_max_sum(root->right);
        max_path_sum = max((root->val + left + right), max_path_sum);
        // cout<< " max_path_sum " << max_path_sum <<" root->val " << root->val << endl;
        int sum = root->val + max(left, right);
        return max(sum, 0);
    }
};
