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
    int dfs(TreeNode* root, int& maxm){
        if(!root) return 0;

        int left = dfs(root->left,maxm);
        int right = dfs(root->right,maxm);

        maxm = max({maxm,left,right,left+right});

        return 1+max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxm = 0;
        int it = dfs(root,maxm);
        return maxm;    
    }
};