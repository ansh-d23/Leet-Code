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

    void dfs(TreeNode* root , int& sum, int& count){

        if(root==nullptr) return;

        sum+=root->val;
        count++;

        dfs(root->left,sum,count);
        dfs(root->right,sum,count);
    }

    int averageOfSubtree(TreeNode* root) {

        if(root==nullptr) return 0;

        queue<TreeNode*> que;
        que.push(root);
        int ans=0;

        while(!que.empty()){
            int n = que.size();
            
            for(int i=0;i<n;i++){
                TreeNode* temp = que.front();
                que.pop();

                int count=0;
                int sum=0;
                dfs(temp,sum,count);
                cout<<sum<<" "<<count<<endl;
                if(count!=0){
                    if(sum/count == temp->val) ans++;
                }
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
        }

        return ans;
        
    }
};