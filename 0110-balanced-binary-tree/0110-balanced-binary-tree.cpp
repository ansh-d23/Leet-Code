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
    int dfstree(TreeNode* root){
        if(root == nullptr) return 0;

        int left  = dfstree(root->left);
        int right = dfstree(root->right);

        if(left==-1 || right==-1) return -1;
        if(abs(left-right) > 1) return -1;

        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {

        return dfstree(root) != -1;
        
    }
};