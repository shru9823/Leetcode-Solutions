class Solution {
public:
    int find(vector<int>& parent, int ele){
        while(parent[ele] != ele){
            ele = parent[ele];
        }
        return ele;
    }
    int do_union(vector<int>& parent,vector<int>& size, int x, int y){
        int p1=find(parent,x),p2=find(parent,y);
        if(p1==p2){return 0;}
        else if(size[p1] > size[p2]){
            size[p1] += size[p2];
            parent[p2] = p1;
        }else{
            size[p2] += size[p1];
            parent[p1] = p2;
        }
        return 1;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n),size(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        int comp=n;
        for(int i=0;i<edges.size();i++){
            comp -= do_union(parent,size, edges[i][0], edges[i][1]);
        }
        return comp;
    }
};