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
    unordered_map<TreeNode*, TreeNode*> par;

    void inOrder(TreeNode* root){
        if(root==nullptr) return;

        if(root->left != nullptr) par[root->left] = root;
        inOrder(root->left);
        if(root->right != nullptr) par[root->right] = root;
        inOrder(root->right);
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        if(root==nullptr) return {};

        vector<int> result;
        inOrder(root);

        unordered_set<int> vis;
        queue<pair<TreeNode*,int>> que;
        que.push({target,0});

        while(!que.empty()){
            int size = que.size();

            for(int i=0;i<size;i++){
                auto it = que.front();
                TreeNode* node = it.first;
                int val = it.second;
                vis.insert(node->val);
                que.pop();

                if(val==k){
                    result.push_back(node->val);
                }

                if(node->left && vis.find(node->left->val) == vis.end()){
                    que.push({node->left, val + 1});
                }

                if(node->right && vis.find(node->right->val) == vis.end()){
                    que.push({node->right, val + 1});
                }

                if(par[node] && vis.find(par[node]->val) == vis.end()){
                    que.push({par[node], val + 1});
                }
            }
        }

        return result; 
        
    }
};