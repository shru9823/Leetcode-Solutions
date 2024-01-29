class Solution {
public:
    vector<string> generateParenthesis(int n) {
        queue<pair<string, pair<int,int>>> q;
        q.push(make_pair("", make_pair(0,0)));
        vector<string> ans;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(p.second.first==n && p.second.second == n){
                ans.push_back(p.first);
            }
            else{
                if(p.second.first < n){
                    q.push(make_pair(p.first+"(", make_pair(p.second.first+1, p.second.second)));
                }
                if(p.second.second < n && p.second.second < p.second.first){
                    q.push(make_pair(p.first+")", make_pair(p.second.first, p.second.second+1)));
                }
            }
        }
        return ans;
    }
};