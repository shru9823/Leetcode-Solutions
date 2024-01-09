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
    vector<int> vec;
    int find(TreeNode* root){
        if(root==NULL){return 0;}
        int left = find(root->left);
        int right = find(root->right);
        int totalsum = left+right+root->val;
        vec.push_back(totalsum);
        return totalsum;
    }
    int maxProduct(TreeNode* root) {
        long long total = find(root);
        long long ans=0;
        for(int i=0;i<vec.size();i++){
            ans = max(ans, vec[i] * (total - vec[i]));
        }
        return (int)(ans%1000000007);
    }
};