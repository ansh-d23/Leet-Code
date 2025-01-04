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

    void dfs(TreeNode* root,int maxm, int& count){

        if(root==nullptr) return;
        
        int val = root->val;
        if(val >= maxm){
            count++;
            maxm = val;
        } 

        if(root->left) dfs(root->left,maxm,count);
        if(root->right) dfs(root->right,maxm,count);

    }

    int goodNodes(TreeNode* root) {

        if(!root) return 0;

        int maxm=INT_MIN;
        int count=0;
        dfs(root,maxm,count);

        return count;
        
    }
};