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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(not root) return "N";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::cout<<data<<endl;
        vector<string> splits;
        string token;
        stringstream ss(data);
        while(getline(ss, token, ',')){
            splits.push_back(token);
        }
        int index = 0;
        return construct(splits, splits.size(), index);
        return nullptr;
    }
    TreeNode* construct(vector<string>& data, int size, int& index) {
        if(index >= size or data[index] == "N") {
            ++index;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(data[index++]));
        root->left = construct(data, size, index);
        root->right = construct(data, size, index);
        return root;
    }
};
