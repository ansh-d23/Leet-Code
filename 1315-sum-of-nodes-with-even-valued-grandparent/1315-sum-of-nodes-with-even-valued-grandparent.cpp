class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, int& ans) {
        if (root == nullptr) return;

        if ((root->val) % 2 == 0) {
            if(root->left != nullptr && root->left->left != nullptr) ans+= (root->left->left->val);
            if(root->left != nullptr && root->left->right != nullptr) ans+= (root->left->right->val);
            if(root->right != nullptr && root->right->right != nullptr) ans+= (root->right->right->val);
            if(root->right != nullptr && root->right->left != nullptr) ans+= (root->right->left->val);
        }
        
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
};
