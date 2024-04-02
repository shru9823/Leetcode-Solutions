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
    int ans=INT_MIN;
    int find(TreeNode* root){
        if(!root){return NULL;}
        int left = find(root->left);
        int right = find(root->right);
        ans=max(max(ans,root->val), max(root->val+left+right,root->val+max(left,right)));
        return max(max(left,right)+root->val, root->val);
    }
    int maxPathSum(TreeNode* root) {
        find(root);
        return ans;
    }
};