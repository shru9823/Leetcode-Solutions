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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        if(root==NULL){return {};}
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int prev=0;
            while(size--){
                auto a = q.front();q.pop();
                if(a->left){q.push(a->left);}
                if(a->right){q.push(a->right);}
                prev = a->val;
            }
            vec.push_back(prev);
        }
        return vec;
    }
};