class Solution {
public:
    vector<vector<int>> temp = {{0,1},{0,-1},{1,0},{-1,0}};
    bool is_valid(int i,int j, vector<vector<int>>& vec){
        if(i<0 || i>= vec.size() || j<0 || j>=vec[0].size()){return 0;}
        return true;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& vec, int i, int j){
        
        if(vec[i][j]){return vec[i][j];}
        vec[i][j] = 1;
        for(int a=0;a<4;a++){
            int x=i+temp[a][0], y=j+temp[a][1];
            if(is_valid(x,y, vec) && matrix[i][j] < matrix[x][y]){
                vec[i][j] = max(vec[i][j], dfs(matrix, vec, x, y) + 1);
            }
        }
        return vec[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size(),ans=0;
        vector<vector<int>> vec(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vec[i][j]==0){
                    ans = max(ans, dfs(matrix, vec, i, j));
                }
            }
        }
        return ans;
    }
};