class Solution {
public:
    double find(map<string, map<string, double>>& mp, set<string>& visi, string curr, string target, double prod){
        visi.insert(curr);
        double ans = -1.0;
        map<string, double> mmp= mp[curr];
        if(mmp.find(target) != mmp.end()){
            ans = prod * mmp[target];
        }else{
            for(auto p:mmp){
                string a = p.first;
                if(visi.find(a) == visi.end()){
                    ans = find(mp, visi, a, target, prod*p.second);
                }else{continue;}
                if(ans != -1.0){
                    break;
                }
            }
        }
        visi.erase(curr);
        return ans;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, map<string, double>> mp;
        for(int i=0;i<equations.size();i++){
            mp[equations[i][0]][equations[i][1]] = values[i];
            
            mp[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        
        vector<double> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            if(mp.find(queries[i][0]) == mp.end() || mp.find(queries[i][1]) == mp.end()){
                ans[i] = -1.0;
            }else if(queries[i][0]==queries[i][1]){
                ans[i] = 1.0;
            }else{
                set<string> visi;
                ans[i] = find(mp, visi, queries[i][0], queries[i][1], 1);
            }
        }
        return ans;
    }
};