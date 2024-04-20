class Solution {
public:
    int dfs(int x, int y, vector<vector<pair<bool, int>>>& vec){
        if(vec[x][y].first){return vec[x][y].second;}
        if(x==0 && y==0){return 0;}
        else if(x+y == 2){return 2;}
        else{
            vec[x][y] = make_pair(true, min(dfs(abs(x-1),abs(y-2),vec),dfs(abs(x-2),abs(y-1),vec))+1);
            return vec[x][y].second;
        }
    }
    int minKnightMoves(int x, int y) {
        vector<vector<pair<bool, int>>> vec(301,vector<pair<bool, int>>(301,make_pair(false,0)));
        return dfs(abs(x),abs(y), vec);
    }
};