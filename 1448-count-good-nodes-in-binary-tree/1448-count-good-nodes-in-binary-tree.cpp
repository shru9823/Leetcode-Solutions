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
    void find(int &ans, TreeNode* root, int maxi){
        if(root==NULL){
            return;
        }
        if(maxi <= root->val){ans++;}
        find(ans, root->left, max(maxi, root->val));
        find(ans, root->right, max(maxi, root->val));
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        find(ans, root, INT_MIN);
        return ans;
    }
};