/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* clone, TreeNode* target, TreeNode*& ans){
        if(clone == nullptr) return;

        if(clone->val == target->val){
            ans=clone;
        }

        dfs(clone->left,target,ans);
        dfs(clone->right,target,ans);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(original==nullptr) return nullptr;

        TreeNode* ans;
        dfs(cloned, target,ans);
        return ans;
    }
};