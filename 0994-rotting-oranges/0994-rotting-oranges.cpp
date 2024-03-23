class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int ans=0, flag=0;
        while(!q.empty()){
            int size = q.size();
            ans += flag==0?0:1;
            flag=1;
            while(size--){
                auto p = q.front();
                q.pop();
                int i=p.first, j=p.second;
                if(i+1 < n && grid[i+1][j] == 1){
                    q.push(make_pair(i+1,j));
                    grid[i+1][j] = 2;
                    fresh--;
                }
                if(i-1 >= 0 && grid[i-1][j] == 1){
                    q.push(make_pair(i-1,j));
                    fresh--;
                    grid[i-1][j]=2;
                }
                if(j+1 < m && grid[i][j+1] == 1){
                    q.push(make_pair(i,j+1));
                    fresh--;
                    grid[i][j+1]=2;
                }
                if(j-1 >= 0 && grid[i][j-1] == 1){
                    q.push(make_pair(i,j-1));
                    fresh--;
                    grid[i][j-1]=2;
                }
            }
        }
        return fresh==0?ans:-1;
    }
};