class Solution {
public:
    bool find(string s1, int i, string s2, int j, string s3, int k, vector<vector<int>> &memo){
        if(s1.length()==i){return s2.substr(j) == s3.substr(k);}
        if(s2.length()==j){return s1.substr(i) == s3.substr(k);}
        if(memo[i][j] != 0){return memo[i][j] == -1?false:true;}
        bool a=false, b=false;
        if(s1[i] == s3[k]){
            a = find(s1, i+1, s2, j, s3, k+1, memo);
            memo[i+1][j] = a==false?-1:1;
        }
        if(s2[j] == s3[k]){
            b = find(s1, i, s2, j+1, s3, k+1, memo);
            memo[i][j+1] = b==false?-1:1;
        }
        if(s1[i] !=s3[k] && s2[j] != s3[k]){return false;}
        return a||b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        // if(s1.length()+s2.length() != s3.length()){return false;}
        // vector<vector<int>> memo(s1.length()+1, vector<int>(s2.length()+1, 0));
        // return find(s1, 0,s2,0, s3,0, memo);
        int m=s1.length(), n=s2.length(), k=s3.length();
        if(m+n != k){return false;}
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, 0));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 && j==0){dp[i][j]=1;}
                else if(i==0){dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[j-1]); }
                else if(j==0){dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i-1]; }
                else{
                    dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[j+i-1]) || (dp[i][j-1] && s2[j-1]==s3[j+i-1]);
                }
            }
        }
        return dp[m][n];
    }
};