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
    void dfs(TreeNode* root, vector<int>& ans){
        if(root == nullptr){
            return;
        }

        dfs(root->left,ans);
        ans.push_back(root->val);
        dfs(root->right,ans);
    }

    bool isValidBST(TreeNode* root) {

        vector<int> ans;
        dfs(root, ans);

        for(int i=0;i<ans.size()-1;i++){
            if(ans[i+1] <= ans[i]){
                return false;
            }
        }

        return true;
        
    }
};