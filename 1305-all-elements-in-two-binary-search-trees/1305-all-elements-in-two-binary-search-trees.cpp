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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1, st2;
        vector<int> vec;
        while(root1 != NULL || root2 != NULL || !st1.empty() || !st2.empty()){
            while(root1){
                st1.push(root1);
                root1 = root1->left;
            }
            while(root2){
                st2.push(root2);
                root2 = root2->left;
            }
            if(st2.empty() || !st1.empty() && st1.top()->val <= st2.top()->val){
                root1 = st1.top();
                vec.push_back(st1.top()->val);
                st1.pop();
                root1 = root1->right;
            }
            else{
                root2 = st2.top();
                vec.push_back(st2.top()->val);
                st2.pop();
                root2 = root2->right;
            }
        }
        return vec;
    }
};