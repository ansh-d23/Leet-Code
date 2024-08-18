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
    TreeNode* Right(TreeNode* root){
        if(root->right ==nullptr) return root;
        return Right(root->right);
    }
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* farRight = Right(root->left);
        farRight->right = rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root==nullptr) return root;

        if(root->val == key) return helper(root);
        TreeNode* dummy = root;

        while(root != nullptr){

            if(key < root->val){
                if(root->left != nullptr && root->left->val ==key){
                    // connect
                    root->left = helper(root->left);
                }else{
                    root=root->left;
                }}else{
                    if(root->right != nullptr && root->right->val == key){
                        //connect
                        root->right = helper(root->right);
                    }else{
                        root=root->right;
                    }
                }
        }

        return dummy;
        
    }
};