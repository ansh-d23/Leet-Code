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
    TreeNode* dnq(vector<int>& post, int pstart, int pend, vector<int>& inorder, int instart, int inend, unordered_map<int,int>& mpp){

        if(pstart < pend || instart > inend) return nullptr;

        TreeNode* root = new TreeNode(post[pstart]);

        int idx_at_in = mpp[post[pstart]];
        int count_node_right = inend - idx_at_in;

        root->left = dnq(post, pstart-count_node_right-1, pend, inorder, instart, idx_at_in-1, mpp);
        root->right = dnq(post, pstart-1, pstart-count_node_right, inorder, idx_at_in+1, inend, mpp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int,int> mpp;
        int n = postorder.size();
        for(int i=0;i<n;i++) mpp[inorder[i]]=i;

        return dnq(postorder,n-1,0,inorder,0,n-1,mpp);
    }
};