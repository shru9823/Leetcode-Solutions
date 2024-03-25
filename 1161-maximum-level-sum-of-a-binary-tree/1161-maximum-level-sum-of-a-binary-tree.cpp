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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL){return 0;}
        int level=0, ret=0, ans=INT_MIN;
        int size=0;
        q.push(root);
        while(!q.empty()){
            size = q.size();
            level++;
            int sum = 0;
            while(size--){
                auto t = q.front();q.pop();
                sum += t->val;
                if(t->left){q.push(t->left);}
                if(t->right){q.push(t->right);}
            }
            if(ans< sum){ret = level;ans=sum;}
        }
        return ret;
    }
};