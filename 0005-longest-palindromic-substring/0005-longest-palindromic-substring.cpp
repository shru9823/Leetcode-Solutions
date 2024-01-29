class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.length(),a=0,b=0;
        vector<vector<bool>> dp(n+1, vector<bool>(n+1,0));
        for(int i=1;i<=n;i++){
            dp[i][i] = 1;
        }
        for(int i=1;i<n;i++){
            if(s[i-1] == s[i]){dp[i][i+1]=1;a=i-1;b=i;}
        }
        for(int i=3;i<=n;i++){
            int k=1;
            for(int j=i;j<=n;j++){
                if(s[k-1]==s[j-1]){
                    if(dp[k+1][j-1]==1){
                        dp[k][j]=1;
                        a=k-1;b=j-1;
                    }
                }
                k++;
            }
        }
        return s.substr(a,b-a+1);
    }
};