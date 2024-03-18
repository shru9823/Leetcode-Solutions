class Solution {
public:
    void find(int& cnt, vector<vector<pair<int,int>>> &vec, int node, int parent){
        for(int i=0;i<vec[node].size();i++){
            if(vec[node][i].first != parent && vec[node][i].second == 1){
                cnt++;
            }
            if(vec[node][i].first != parent){
                find(cnt, vec, vec[node][i].first, node);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> vec(n);
        for(int i=0;i<connections.size();i++){
            vec[connections[i][0]].push_back(make_pair(connections[i][1], 1));
            vec[connections[i][1]].push_back(make_pair(connections[i][0], 0));
        }
        int cnt=0;
        find(cnt, vec, 0, -1);
        return cnt;
    }
};