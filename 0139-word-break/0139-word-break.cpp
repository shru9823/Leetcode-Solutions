class Trie{
    public:
    bool word=false;
    vector<Trie*> vec;
    Trie(){
        vec.resize(26);
    }
    
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie *root=new Trie();
        Trie* cur;
        for(string str:wordDict){
            cur=root;
            for(char a:str){
                if(cur->vec[a-'a'] == NULL){
                    cur->vec[a-'a'] = new Trie();
                }
                cur = cur->vec[a-'a'];
            }
            cur->word = true;
        }
        int n=s.length();
        vector<bool> dp(n,0);
        for(int i=0;i<n;i++){
            cur=root;
            if(i==0 || dp[i-1]){
                for(int j=i;j<n;j++){
                    if(cur->vec[s[j]-'a']){
                        cur = cur->vec[s[j]-'a'];
                        if(cur->word){dp[j]=true;}
                    }else{break;}
                }
            }
        }
        return dp[n-1];
    }
};