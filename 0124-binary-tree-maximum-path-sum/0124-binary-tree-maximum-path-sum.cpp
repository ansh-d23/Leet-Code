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
    int dfs(TreeNode* root, int& maxi){
        if(root == nullptr) return 0;

        int left =  dfs(root->left,maxi) ;
        int right =  dfs(root->right,maxi) ;

        int ans = max({root->val, root->val + left, root->val + right});
        maxi = max({maxi, ans,root->val + right +left});
        return ans;
    }

    int maxPathSum(TreeNode* root) {

        int maxi = INT_MIN;

        dfs(root,maxi);

        return maxi;
    }
};