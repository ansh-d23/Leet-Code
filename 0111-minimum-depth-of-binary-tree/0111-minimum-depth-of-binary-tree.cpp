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
    int minDepth(TreeNode* root) {

        if(root==nullptr) return 0;

        if(root->left==nullptr && root->right==nullptr) return 1;

        int left = root->left != nullptr ? minDepth(root->left) : INT_MAX;
        int right = root->right != nullptr ? minDepth(root->right) : INT_MAX;

        return 1 + min(left,right);
        
    }
};