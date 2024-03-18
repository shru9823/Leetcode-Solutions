class Solution {
public:
    
    void find(int k, vector<vector<int>>& isConnected, vector<bool>& visi){
        for(int i=0; i<isConnected[k].size();i++){
            if(isConnected[k][i]==1 && !visi[i]){
                visi[i]=true;
                find(i, isConnected, visi);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(), m=isConnected[0].size();
        int cnt=0;
        vector<bool> visi(n, false);
        for(int i=0;i<n;i++){
            if(visi[i] == 0){
                visi[i]=true;
                cnt++;
                find(i, isConnected, visi);
            }
        }
        return cnt;
    }
};