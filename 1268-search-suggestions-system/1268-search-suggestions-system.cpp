class node{
    public:
    bool is_end = false;
    vector<node*> vec;
    node(){
        vec.resize(26, NULL);
    }
};

class Solution {
public:
    node* root;
    Solution(){
        root = new node();
    }
    
    void insert(string word){
        node* t=root;
        for(char c:word){
            if(t->vec[c-'a'] == NULL){
                t->vec[c-'a'] = new node();
            }
            t=t->vec[c-'a'];
        }
        t->is_end = true;
    }
    
    void dfs(node* curr, vector<string>&res, string word_so_far){
        if(res.size()==3){
            return;
        }
        if(curr->is_end){res.push_back(word_so_far);}
        for(char c='a';c<='z';c++){
            if(curr->vec[c-'a']){
                string word = word_so_far+c;
                dfs(curr->vec[c-'a'], res, word);
            }
        }
    }
    
    vector<string> find(string prefix){
        vector<string> res;
        
        node* t=root;
        int i=0;
        for(char c:prefix){
            if(!t->vec[c-'a']){
                return res;
            }
            t = t->vec[c-'a'];
        }
        dfs(t, res, prefix);
        return res;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& prod, string searchWord) {
        string prefix="";
        int n = prod.size();
        for(int i=0;i<n;i++){
            insert(prod[i]);
        }
        vector<vector<string>> ans;
        for(char a:searchWord){
            prefix += a;
            ans.push_back(find(prefix));
        }
        return ans;
    }
};