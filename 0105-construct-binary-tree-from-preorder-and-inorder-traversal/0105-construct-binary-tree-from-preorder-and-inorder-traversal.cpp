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
    map<int, int> mp;
    TreeNode* find(vector<int>& preorder, vector<int>& inorder, int l, int r, int ind){
        int n=preorder.size();
        if(l>r ){return NULL;}
        TreeNode* root = new TreeNode(preorder[ind]);
        root->left = find(preorder, inorder, l, mp[preorder[ind]]-1, ind+1);
        root->right = find(preorder, inorder, mp[preorder[ind]]+1, r, ind+mp[preorder[ind]]-l+1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return find(preorder, inorder, 0, n-1, 0);
    }
};