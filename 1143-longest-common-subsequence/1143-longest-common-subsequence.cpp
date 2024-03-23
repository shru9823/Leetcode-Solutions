class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(), m=text2.length();
        if(n<m){
            swap(n,m);
            swap(text1, text2);
        }
        vector<int> prev(m+1,0), cur(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    cur[j] = prev[j-1]+1;
                }else{
                    cur[j] = max(prev[j], cur[j-1]);
                }
            }
            swap(cur, prev);
        }
        return prev[m];
    }
};