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
    TreeNode* dfs(TreeNode* root, vector<int>& v){
        if(!root){
            return NULL;
        }
        if(!root->left && !root->right){
            // cout<<root->val<<endl;
            v.push_back(root->val);
            return NULL;
        }
        root->left = dfs(root->left, v);
        root->right = dfs(root->right, v);
        return root;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(root==NULL){return {};}
        vector<vector<int>> vec;
        while(root){
            vector<int> v;
            root = dfs(root, v);
            vec.push_back(v);
        }
        return vec;
    }
};