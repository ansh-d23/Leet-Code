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
    vector<int> inorderTraversal(TreeNode* root) {

        stack<TreeNode*> stk;
        vector<int> inOrder;

        TreeNode* node = root;

        while(true){

            if(node == NULL){
                if(stk.empty()) break;
                node = stk.top();
                stk.pop();
                inOrder.push_back(node->val);
                node=node->right;
            }else{
                stk.push(node);
                node=node->left;
            }
        }  
        return inOrder;
    }
};