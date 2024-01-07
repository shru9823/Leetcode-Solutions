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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL){return 0;}
        int ans=0;
        queue<TreeNode*> q;
        TreeNode* temp = NULL;
        q.push(root);
        while(1){
            int n=q.size();
            if(n==0){break;}
            ans=0;
            while(n){
                temp = q.front();
                q.pop();
                ans += temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                n--;
            }
        }
        return ans;
    }
};