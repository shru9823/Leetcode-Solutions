class Solution {
public:
    void find(vector<vector<string>> &ans, string s, int start, vector<string> &vec, vector<vector<bool>> &dp){
        if(start >= s.length()){
            ans.push_back(vec);
        }
        for(int end = start; end < s.length(); end++){
            if(s[start] == s[end] && (end-start <= 2 || dp[start+1][end-1] == true)){
                dp[start][end] = true;
                vec.push_back(s.substr(start, end-start+1));
                find(ans, s, end+1, vec, dp);
                vec.erase(vec.end()-1);
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<vector<bool>> dp(n, vector<bool> (n,false));
        vector<string> vec;
        find(ans, s, 0, vec, dp);
        return ans;
    }
};

// class Solution {
// public:
//     string a;
//     map<int, vector<vector<string>> > mp;
//     vector<vector<string>> find(int s, vector<vector<bool>>& dp){
//         if(s == a.length()){
//             return {{}};
//         }
//         if(mp.find(s) != mp.end()){return mp[s];}
//         vector<vector<string>> ans;
//         for(int j=s;j<a.length();j++){
//             if((j-s <= 2 || dp[s+1][j-1] == true) && a[j]==a[s]){
//                 dp[s][j]=true;
//                 string x = a.substr(s, j-s+1);
//                 auto res = find(j+1, dp);
//                 if(res.empty()){res.push_back({x});}
//                 for(auto &temp:res){
//                     temp.insert(temp.begin(), x);
//                     ans.push_back(temp);
//                 }
//             }
//         }
//         mp[s] = ans;
//         return ans;
//     }
//     vector<vector<string>> partition(string s) {
//         a=s;
//         int n=s.length();
//         vector<vector<bool>> dp(n, vector<bool>(n, false));
//         return find(0, dp);
//     }
// };