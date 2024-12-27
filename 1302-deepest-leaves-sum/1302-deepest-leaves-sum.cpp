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

    int lvl(TreeNode* root){

        if(root==nullptr) return 0;

        int left = lvl(root->left);
        int right = lvl(root->right);

        return max(left,right)+1;
    }

    void dfs(TreeNode* root, int& ans,int l,int lvl){

        if(root==nullptr) return;

        if(l==lvl){
            ans += root->val;
        }

        dfs(root->left, ans, l + 1, lvl);
        dfs(root->right, ans, l + 1, lvl);
    }

    int deepestLeavesSum(TreeNode* root) {

        if(root==nullptr) return 0;
        int l = lvl(root);
        int ans=0;
        dfs(root,ans,1,l);
        return ans;   
    }
};