class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> vec(n,1);
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==1 && j==0){continue;}
                vec[j] += j-1>=0 ? vec[j-1]:0;
            }
        }
        return vec[n-1];
    }
};