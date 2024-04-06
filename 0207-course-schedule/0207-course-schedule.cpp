class Solution {
public:
//     bool find(vector<vector<int>>& vec, int parent,int cur, vector<bool>&visi){
//         visi[cur]=true;
//         for(int a:vec[cur]){
//             if(a==parent){
//                 // visi[cur]=false;
//                 return false;}
//             if(!visi[a]){
//                 if(!find(vec, parent, a, visi)){
//                     // visi[cur]=false;
//                     return false;
//                 }
//             }
//         }
//         // visi[cur]=false;
//         return true;
//     }
//     bool canFinish(int n, vector<vector<int>>& prerequisites) {
//         vector<bool> visi(n), v(n); 
//         vector<vector<int>> vec(n);
        
//         for(int i=0;i<prerequisites.size();i++){
//             vec[prerequisites[i][0]].push_back(prerequisites[i][1]);
//         }
//         for(int i=0;i<n;i++){
//             if(!visi[i]){
//                 if(!find(vec, i,i, visi)){return false;}
//                 // visi.assign(n,false);
//                 visi=v;
//             }
//         }
//         return true;
//     }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> in(n); 
        vector<vector<int>> vec(n);
        
        for(int i=0;i<prerequisites.size();i++){
            vec[prerequisites[i][0]].push_back(prerequisites[i][1]);
            in[prerequisites[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        int a=q.size();
        while(!q.empty()){
            int ele= q.front();q.pop();
            for(int c:vec[ele]){
                in[c]--;
                if(in[c]==0){q.push(c);a++;}
            }
        }
        return a==n;
    }
};