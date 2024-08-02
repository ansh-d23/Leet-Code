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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> que;
        que.push(root);
        int cnt = 0;

        while(!que.empty()){
            int n = que.size();
            vector<int> level;

            for(int i=0;i<n;i++){
                    TreeNode* top = que.front();
                    que.pop();
                    if(top->left != nullptr) que.push(top->left);
                    if(top->right != nullptr) que.push(top->right);
                    level.push_back(top->val);
            }

            if(cnt%2 !=0) reverse(level.begin(),level.end());
            ans.push_back(level);
            cnt++;

        }

        return ans;
        
    }
};