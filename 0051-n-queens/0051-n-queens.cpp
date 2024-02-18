class Solution {
public:
    vector<vector<string>> ans;
    int N=0;
    void find(int row, set<int>& dia, set<int>& adia, set<int>& col, vector<string>  &a){
        if(row == N){ans.push_back(a);return;}
        for(int c=0;c<N;c++){
            int d = row-c,ad=row+c;
            if(col.find(c) == col.end() && dia.find(d) == dia.end() && adia.find(ad) == adia.end()){
                a[row][c] = 'Q';
                col.insert(c);dia.insert(d);adia.insert(ad);
                find(row+1, dia, adia, col, a);
                a[row][c] = '.';
                col.erase(c);dia.erase(d);adia.erase(ad);
            }
            else{continue;}
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> a;
        N=n;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<n;j++){
                temp += ".";
            }
            a.push_back(temp);
        }
        set<int> dia,adia,col;
        find(0,dia,adia,col,a);
        return ans;
    }
};