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
    vector<TreeNode*> find(int start, int end){
        if(start > end){return {NULL};}
        if(start==end){
            return {new TreeNode(start)};
        }
        vector<TreeNode*> ans;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left = find(start, i-1);
            vector<TreeNode*> right = find(i+1, end);
            for(int a=0;a<left.size();a++){
                for(int b=0;b<right.size();b++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[a];
                    root->right = right[b];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return find(1, n);
    }
};