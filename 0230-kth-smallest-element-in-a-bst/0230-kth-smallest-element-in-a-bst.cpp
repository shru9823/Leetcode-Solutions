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
    int res=0, kk=0;
    void find(TreeNode* root, int& cnt){
        if(root==NULL || cnt>=kk){return;}
        find(root->left, cnt);
        cnt++;
        if(cnt==kk){
            res=root->val;
            return;
        }
        find(root->right, cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int a=0;
        kk=k;
        find(root, a);
        return res;
    }
};