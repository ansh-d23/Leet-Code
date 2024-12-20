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
    TreeNode* reverseOddLevels(TreeNode* root) {

        queue<TreeNode*> que;
        que.push(root);
        int level=0;

        while(!que.empty()){
            int size = que.size();
            vector<TreeNode*> levelNode;
            
            for(int i=0;i<size;i++){
                TreeNode* temp = que.front();
                que.pop();
                levelNode.push_back(temp);
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }

            if(level%2 != 0){
                //swap
                int l=0;
                int r=levelNode.size()-1;
                while(l<r){
                    swap(levelNode[l]->val,levelNode[r]->val);
                    l++;
                    r--;
                }
            }

            level++;
        }

        return root;
        
    }
};