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
    int dfs(TreeNode* root, int &maxi){
        if(root==nullptr) return 0;

        int left = dfs(root->left, maxi);  
        int right = dfs(root->right, maxi);

        maxi = max({maxi , root->val + left + right, root->val + max({left , right}),root->val});
        return max(root->val + max({left , right}), root->val);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int ans = dfs(root,maxi);
        return maxi;    
    }
};