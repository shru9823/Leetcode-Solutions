class Solution {
public:
    bool find(vector<vector<int>>& vec, int parent,int cur, vector<bool>&visi){
        visi[cur]=true;
        for(int a:vec[cur]){
            if(a==parent){return false;}
            if(!visi[a]){
                if(!find(vec, parent, a, visi)){
                    return false;
                }
            }
        }
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> visi(n); 
        vector<vector<int>> vec(n);
        
        for(int i=0;i<prerequisites.size();i++){
            vec[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<n;i++){
            if(!visi[i]){
                if(!find(vec, i,i, visi)){return false;}
                visi.assign(n,false);
            }
        }
        return true;
    }
};