class Solution {
public:
    bool valid(int n,int m, int x, int y){
        return (x>=0 && x<n && y>=0 && y<m);
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(), m=board[0].size(), k=8;
        vector<vector<int>> vec = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,1},{1,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                for(int l=0;l<k;l++){
                    int a1=i+vec[l][0],a2=j+vec[l][1];
                    if(valid(n,m,a1,a2)){
                        // cout<<a1<<" "<<a2<<endl;
                        if(board[a1][a2] == 1 || board[a1][a2] == 11 || board[a1][a2] == -9){cnt++;}
                    }
                }
                // cout<<i<<" "<<j<<" "<<cnt<<endl;
                if((board[i][j]==0) && (cnt ==3)){board[i][j] += 10;}
                else if((board[i][j]==1) && (cnt == 2 || cnt == 3)){board[i][j] += 10;}
                else{board[i][j] -= 10;}
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] > 0){
                    board[i][j] = 1;
                }else{
                    board[i][j] = 0;
                }
            }
        }
    }
};