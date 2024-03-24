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
    int find(TreeNode* root, int dir, int& ans){
        if(root == NULL){return 0;}
        int left = find(root->left, 0, ans);
        int right = find(root->right, 1, ans);
        ans = max(ans, 1+max(left,right));
        // cout<<ans<<" "<<left<<" "<<right<<endl;
        if(dir == -1){return ans;}
        if(dir == 0){
            right++;
            return right;
        }
        left++;
        return left;
    }
    int longestZigZag(TreeNode* root) {
        int ans=0;
        return find(root, -1, ans)-1;
    }
};