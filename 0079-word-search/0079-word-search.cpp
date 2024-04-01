class Solution {
public:
    bool find(int r, int c, vector<vector<char>>& board, string& word, int index){
        if(index == word.length()){return true;}
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c] != word[index]){return false;}
        bool ret=false;
        board[r][c] = '@';
        ret = find(r+1,c, board, word, index+1) || find(r-1,c, board, word, index+1) || find(r,c+1, board, word, index+1) || find(r,c-1, board, word, index+1);
        board[r][c] = word[index];
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(find(i,j, board, word, 0)){return true;}
                }
            }
        }
        return false;
    }
};