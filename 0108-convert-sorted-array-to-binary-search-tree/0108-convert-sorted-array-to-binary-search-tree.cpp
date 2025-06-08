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
    TreeNode* create(vector<int>& nums,int l, int r){
        if(l>r) return nullptr;

        int mid  = l+(r-l)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);

        newNode->left = create(nums,l,mid-1);
        newNode->right = create(nums,mid+1,r);

        return newNode;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return create(nums,0,n-1);
    }
};