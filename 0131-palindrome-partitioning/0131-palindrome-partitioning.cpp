class Solution {
public:
    string a;
    map<int, vector<vector<string>> > mp;
    vector<vector<string>> find(int s, vector<vector<bool>>& dp){
        if(s == a.length()){
            return {{}};
        }
        if(mp.find(s) != mp.end()){return mp[s];}
        vector<vector<string>> ans;
        for(int j=s;j<a.length();j++){
            if((j-s <= 2 || dp[s+1][j-1] == true) && a[j]==a[s]){
                dp[s][j]=true;
                string x = a.substr(s, j-s+1);
                auto res = find(j+1, dp);
                if(res.empty()){res.push_back({x});}
                for(auto &temp:res){
                    temp.insert(temp.begin(), x);
                    ans.push_back(temp);
                }
            }
        }
        mp[s] = ans;
        return ans;
    }
    vector<vector<string>> partition(string s) {
        a=s;
        int n=s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        return find(0, dp);
    }
};