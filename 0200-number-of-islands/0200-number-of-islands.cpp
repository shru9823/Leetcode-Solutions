class Solution {
public:
    void find(vector<vector<char>>& grid, int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>= grid[0].size() || grid[i][j] == '0'){return;}
        
        grid[i][j] = '0';
        find(grid, i+1,j);
        find(grid, i-1,j);
        find(grid, i,j-1);
        find(grid, i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0, n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    ans++;
                    find(grid, i, j);
                }
            }
        }
        return ans;
    }
};