class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] != 'X'){continue;}
                // if(i-1>=0 && j-1>=0){
                    if((i-1>=0 && board[i-1][j]=='X') || (j-1>=0 && board[i][j-1] == 'X')){continue;}
                    else{ans++;}
                // }else if(i-1>=0){
                //     if(board[i-1][j]=='X'){continue;}
                //     else{ans++;}
                // }else if(j-1 >= 0){
                //     if(board[i][j-1]=='X'){continue;}
                //     else{ans++;}
                // }else{
                //     ans++;
                // }
            }
        }
        return ans;
    }
};