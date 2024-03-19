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
    map<long,int> mp;
    void find(int & cnt, TreeNode* root, long curr, int t){
        if(root==NULL){
            return;
        }
        curr += root->val;
        if(curr==t){
            cnt++;
        }
        cnt += mp[curr-t];
        
        mp[curr]++;
        find(cnt, root->left, curr, t);
        find(cnt, root->right, curr, t);
        
        mp[curr]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        find(ans, root, 0, targetSum);
        return ans;
    }
};