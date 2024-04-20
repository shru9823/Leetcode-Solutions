class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int x=0,y=0,a=0,b=0,n=land.size(),m=land[0].size();
        vector<vector<int>> ans;
        for(a=0;a<n;a++){
            for(b=0;b<m;b++){
                if(land[a][b] == 1){
                    for(x=a;x<n && land[x][b]==1;x++){
                        for(y=b;y<m && land[x][y]==1;y++){
                            land[x][y]=0;
                        }
                    }
                    ans.push_back({a,b,x-1,y-1});
                }
            }
        }
        return ans;
    }
};