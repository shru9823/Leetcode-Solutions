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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root == NULL){return {};}
        if(root->left==NULL && root->right==NULL){return {root->val};}
        vector<int> vec,vec_l,vec_r;
        vec.push_back(root->val);
        TreeNode* cur = root->left;
        while(cur){
            if(cur->left!=NULL || cur->right !=NULL){vec.push_back(cur->val);}
            if(cur->left){cur = cur->left;}
            else{cur = cur->right;}
        }
        stack<TreeNode*> st;
        cur = root;
        st.push(cur);
        while(!st.empty()){
            cur = st.top();st.pop();
            if(cur->left == NULL && cur->right==NULL){vec_l.push_back(cur->val);}
            if(cur->right){st.push(cur->right);}
            if(cur->left){st.push(cur->left);}
        }
        cur = root->right;
        while(cur){
            if(cur->left!=NULL || cur->right !=NULL){vec_r.push_back(cur->val);}
            if(cur->right){cur = cur->right;}
            else{cur = cur->left;}
        }
        reverse(vec_r.begin(), vec_r.end());
        vec.insert(vec.end(), vec_l.begin(), vec_l.end());
        vec.insert(vec.end(), vec_r.begin(), vec_r.end());
        return vec;
    }
};

