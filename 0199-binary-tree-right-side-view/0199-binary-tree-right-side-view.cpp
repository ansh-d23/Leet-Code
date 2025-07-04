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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        if(root == nullptr) return ans;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){

            int size = que.size();
            vector<int> temp;

            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();

                temp.push_back(node->val);

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            ans.push_back(temp.back());
        } 

        return ans;
    }
};