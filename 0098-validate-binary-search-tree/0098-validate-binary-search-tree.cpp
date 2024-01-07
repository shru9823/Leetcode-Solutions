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
        if (root == NULL){
            return true;
        }
        TreeNode* prev = NULL;
        stack<TreeNode*> s;
        
        TreeNode * current = root;
        while(!s.empty() || current != NULL){
            while(current){
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            if(prev != NULL && current->val <= prev->val){
                return false;
            }
            prev = current;
            // if(current->right){
                current = current->right;
            // }
            
        }
        return true;
    }
};