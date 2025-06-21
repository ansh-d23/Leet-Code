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
    bool isSimilar(TreeNode* p, TreeNode* q){
        if(p==nullptr || q==nullptr){
            return p==q;
        }

        bool valCheck = p->val==q->val ? true : false;
        

        bool leftCheck = isSimilar(p->left,q->left);
        bool rightCheck = isSimilar(p->right,q->right);

        return valCheck && leftCheck && rightCheck;
    }

    void dfs(TreeNode* root, TreeNode* subRoot, bool& flag){

        if(root==nullptr) return;

        if(root->val == subRoot->val){
           flag = isSimilar(root,subRoot);
        }

        dfs(root->left,subRoot,flag);
        dfs(root->right,subRoot,flag);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        //dfs + check similarity

        if(!root || !subRoot) return root==subRoot;

        bool flag =false;
        dfs(root,subRoot,flag);
        return flag;
    }
};