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
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->val%2 == 0){
                if(temp->left){
                    if(temp->left->left){sum += temp->left->left->val;}
                    if(temp->left->right){sum += temp->left->right->val;}
                }
                if(temp->right){
                    if(temp->right->left){sum += temp->right->left->val;}
                    if(temp->right->right){sum += temp->right->right->val;}
                }
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        return sum;
    }
};