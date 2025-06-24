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
    void dfs(TreeNode* root, int& maxm, int& count){

        if(root==nullptr) return;
        
        if(root->val >= maxm){
            count++;
            maxm = max(maxm, root->val);
        }

        dfs(root->left,maxm,count);
        dfs(root->right,maxm,count);

    }
public:
    int goodNodes(TreeNode* root) {

        if(root==nullptr) return 0;

        int count=1;
        int maxm = root->val;
        dfs(root->left,maxm,count);
        dfs(root->right,maxm,count);
        return count;
    }
};