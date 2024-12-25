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
    vector<int> largestValues(TreeNode* root) {

        queue<TreeNode*> que;
        que.push(root);
        vector<int> ans;


        while(!que.empty()){
            int size = que.size();
            int maxm = INT_MIN;

            for(int i=0;i<size;i++){
                TreeNode* temp = que.front();
                que.pop();
                maxm = max(maxm , temp->val);
                if(temp->right){
                    que.push(temp->right);
                }
                if(temp->left){
                    que.push(temp->left);
                }
            }
            ans.push_back(maxm);
        }

        return ans;
        
    }
};