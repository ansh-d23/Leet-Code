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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;
        if(root==nullptr) return ans;

        queue<pair<TreeNode*,pair<int,int>>> que;
         map<int, map<int, multiset<int>>> mpp;

        que.push({root , {0,0}});
        while(!que.empty()){

            auto p  = que.front();
            que.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            mpp[x][y].insert(node->val);
            if (node->left != nullptr) que.push({node->left, {x - 1, y + 1}});
            if (node->right != nullptr) que.push({node->right, {x + 1, y + 1}});
        }

        for(auto it : mpp){
            vector<int> cols;
            for(auto q : it.second){
                cols.insert(cols.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(cols);
        }

        return ans;
        
    }
};