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
        if(not root) return INT_MIN;
        int left = find_max_sum(root->left);
        int right = find_max_sum(root->right);
        int max_val = root->val;
        if (left != INT_MIN and left > 0) max_val += left;
        if (right != INT_MIN and right > 0) max_val += right;
        max_path_sum = max({max_val, left, right, max_path_sum});
        cout<< " max_path_sum " << max_path_sum <<" root->val " << root->val << endl;
        right = max(right, left);
        return right == INT_MIN? root->val : max(root->val + right, root->val);
    }
};
