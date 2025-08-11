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
    bool getpath(TreeNode* root, TreeNode* p, vector<TreeNode*>& arr){
        if(root==nullptr) return false;

        arr.push_back(root);

        if(root->val == p->val) return true;

        bool l = getpath(root->left,p,arr);
        bool r = getpath(root->right,p,arr);

        if(l || r) return true;

        arr.pop_back();

        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> p1;
        vector<TreeNode*> p2;

        bool val1 = getpath(root,p,p1);
        bool val2 = getpath(root,q,p2);

        int n = p1.size();
        int m = p2.size();

        int i=0;
        TreeNode* ans=root;
        while(i<n && i<m){
            if(p1[i]==p2[i]){
                ans = p1[i];
                i++;
            }else break;
        }

        return ans;
        
    }
};