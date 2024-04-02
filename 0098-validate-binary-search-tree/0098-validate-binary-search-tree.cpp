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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        if(root==NULL){return true;}
        TreeNode * cur = root;
        TreeNode* prev=NULL;
        while(cur || !st.empty()){
            while(cur){
                st.push(cur);cur=cur->left;
            }
            auto a  = st.top();st.pop();
            if(prev && prev->val >= a->val){return false;}
            prev = a;
            if(a->right){cur = a->right;}
        }
        return true;
    }
};