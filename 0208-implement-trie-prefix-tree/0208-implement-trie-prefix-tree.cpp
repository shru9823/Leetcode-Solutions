class node{
    public:
    bool is_end=false;
    vector<node*> vec;
    node(){
        vec.resize(26, NULL);
    }
};
class Trie {
public:
    
    node *root;
    Trie() {
       root = new node(); 
    }
    
    void insert(string word) {
        int n=word.length();
        node* t = root;
        for(int i=0;i<n;i++){
            if(t->vec[word[i]-'a'] == NULL){
                t->vec[word[i]-'a'] = new node();
            }
            t = t->vec[word[i]-'a'];
        }
        t->is_end = true;
    }
    
    bool search(string word) {
        int n=word.length();
        node* t = root;
        for(int i=0;i<n;i++){
            if(t->vec[word[i]-'a'] == NULL){
                return false;
            }
            t = t->vec[word[i]-'a'];
        }
        if(t->is_end){return true;}
        return false;
    }
    
    bool startsWith(string prefix) {
        int n=prefix.length();
        node* t = root;
        for(int i=0;i<n;i++){
            if(t->vec[prefix[i]-'a'] == NULL){
                return false;
            }
            t = t->vec[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */