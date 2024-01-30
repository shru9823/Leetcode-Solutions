class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n=word2.length(), dia=0,cur_dia=0;
        vector<int> vec(n+1,0);
        for(int j=1;j<=n;j++){
            vec[j] = vec[j-1]+1;
        }
        for(int i=0;i<m;i++){
            dia = vec[0];
            vec[0]++;
            for(int j=1;j<=n;j++){
                cur_dia = vec[j];
                if(word1[i] == word2[j-1]){
                    vec[j] = dia;
                }
                else{
                    vec[j] = min(min(1+dia, vec[j-1]+1), 1+vec[j]);
                }
                dia = cur_dia;
            }
        }
        return vec[n];
    }
};