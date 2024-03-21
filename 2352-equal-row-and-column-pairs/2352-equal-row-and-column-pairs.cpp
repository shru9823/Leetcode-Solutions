class TrieNode{
    public:
    int count;
    map<int,TrieNode*> mp;
    TrieNode(){
        count=0;
    }
};

class Solution {
public:
    TrieNode * root;
    Solution(){
        root = new TrieNode();
    }
    void insert(vector<int> vec){
        TrieNode* t=root;
        for(int i=0;i<vec.size();i++){
            if(t->mp.find(vec[i]) == t->mp.end()){
                t->mp[vec[i]] = new TrieNode();
            }
            t = t->mp[vec[i]];
        }
        t->count += 1;
    }
    int search(vector<int> vec){
        TrieNode* t=root;
        for(int i=0;i<vec.size();i++){
            if(t->mp.find(vec[i]) == t->mp.end()){
                return 0;
            }
            t = t->mp[vec[i]];
        }
        return t->count;
    }
    
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        for(int j=0;j<m;j++){
            insert(grid[j]);
        }
        vector<int> t;
        int cnt=0;
        for(int j=0;j<m;j++){
            vector<int> t;
            for(int i=0;i<n;i++){
                t.push_back(grid[i][j]);
            }
            cnt += search(t);
        }
        return cnt;
    }
};