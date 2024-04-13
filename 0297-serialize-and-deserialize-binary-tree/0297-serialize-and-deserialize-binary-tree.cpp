/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string convert(int a){
        if(a==0){return "0";}
        string ret="";
        while(a){
            ret += to_string(a%10);
            a = a/10;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();q.pop();
            if(temp == NULL){
                ans += (ans=="")?"N":",N";
                continue;
            }else{
                ans += (ans=="")?"":",";
                if(temp->val < 0){ans += "-";ans += convert(-1*temp->val);}
                else{ans += convert(temp->val);}
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==1){return NULL;}
        TreeNode* root = new TreeNode(0);
        queue<TreeNode*> q;
        int i=0,n=0;
        if(data[i] == '-'){
            i++;
            while(data[i] != ','){
                n = n*10+( data[i]-'0');i++;
            }
            n *= -1;
        }else{
            while(data[i] != ','){
                n = n*10+( data[i]-'0');i++;
            }
        }
        i++;
        root->val = n;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();q.pop();
            int r=0;
            while(r<2 && i<data.length()){
                if(data[i] == '-'){
                    int num = 0;
                    i++;
                    while(i<data.length() && data[i] != ','){
                        num = num*10 + (data[i]-'0');i++;
                    }
                    num *= -1;
                    if(r==0){temp->left = new TreeNode(num);q.push(temp->left);}
                    else{temp->right = new TreeNode(num);q.push(temp->right);}
                }else if(data[i] != 'N'){
                    int num = 0;
                    while(i<data.length() && data[i] != ','){
                        num = num*10 + (data[i]-'0');i++;
                    }
                    if(r==0){temp->left = new TreeNode(num);q.push(temp->left);}
                    else{temp->right = new TreeNode(num);q.push(temp->right);}
                }else{i++;}
                i++;
                r++;
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));