class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size(), m=maze[0].size();
        vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<array<int,3>>  q;
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto v = q.front();q.pop();
                if(v[0]==0 || v[0]==n-1 || v[1]==0 || v[1]==m-1 ){
                    if(v[0] == entrance[0] && v[1] == entrance[1]){
                        
                    }
                    else{return v[2];}
                }
                for(auto p:dir){
                    int r=p.first+v[0], c=p.second+v[1];
                    if(r>=0 && r<n && c>=0 && c<m && maze[r][c] == '.'){
                        maze[r][c] = '+';
                        q.push({r,c,v[2]+1});
                    }
                }
            }
        }
        return -1;
    }
};