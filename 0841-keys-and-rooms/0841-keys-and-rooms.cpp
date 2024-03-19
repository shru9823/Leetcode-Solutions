class Solution {
public:
    void find(vector<vector<int>>& rooms, vector<bool>& visi, int node, int& cnt){
        cnt--;
        visi[node] = true;
        for(int i=0;i<rooms[node].size();i++){
            if(!visi[rooms[node][i]]){
                find(rooms, visi, rooms[node][i], cnt);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        
        vector<bool> visi(n);
        find(rooms, visi, 0, n);
        return n>0?false:true;
    }
};