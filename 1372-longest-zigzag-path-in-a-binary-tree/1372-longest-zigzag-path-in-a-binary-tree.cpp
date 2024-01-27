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
    int ans = 0;
    pair<int,int> find(TreeNode* root){
        if(root==NULL){
            return make_pair(0,0);
        }
        pair<int, int> p;
        p.first = find(root->left).second;
        p.second = find(root->right).first;
        ans = max(ans, max(p.first, p.second));
        p.first += 1;
        p.second += 1;
        return p;
    }
    int longestZigZag(TreeNode* root) {
        find(root);
        return ans;
    }
};