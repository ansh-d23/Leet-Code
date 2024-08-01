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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root==nullptr) return ans;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){

            int n = que.size();
            vector<int> level;

            for(int i=0;i<n;i++){
                TreeNode* temp = que.front();
                que.pop();
                level.push_back(temp->val);
                if(temp->left != nullptr) que.push(temp->left);
                if(temp->right != nullptr) que.push(temp->right);
            }

            ans.push_back(level);

        }       

        return ans; 
    }
};