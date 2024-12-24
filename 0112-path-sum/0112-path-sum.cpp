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

    bool bfs(TreeNode* root, int& targetSum, int sum){

        sum+= root->val;

        if(root->left==nullptr && root->right==nullptr){
             return (sum == targetSum);
        }

        bool left = root->left != nullptr ? bfs(root->left,targetSum,sum) : false;
        bool right = root->right != nullptr ? bfs(root->right,targetSum,sum) : false;

        return (left || right);

    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==nullptr) return false;

        int sum=0;
        return bfs(root,targetSum,sum);
    }
};