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
    int widthOfBinaryTree(TreeNode* root) {

        if(root==nullptr) return 0;

        long long ans = 0;
        queue<pair<TreeNode*,long long>> que;
        que.push({root,0});

        while(!que.empty()){
            long long size = que.size();
            long long mini = que.front().second;
            long long first,last;
            for(int i=0;i<size;i++){
                long long curr_id = que.front().second - mini;
                TreeNode*  node = que.front().first;
                que.pop();

                if(i==0) first = curr_id;
                if(i==size-1) last = curr_id;
                if(node->left){
                    que.push({node->left,curr_id*2+1});
                }
                if(node->right){
                    que.push({node->right,curr_id*2+2});
                }
            }
            ans = max(ans , last-first+1);
        }
        
        return ans;
    }
};