class Solution {
public:
    int numTrees(int n) {
        int ans=0;
        vector<int> vec(n+1,1);
        for(int i=2;i<=n;i++){
            int t=0;
            for(int j=1;j<=i;j++){
                t += (vec[i-j]*vec[j-1]);
            }
            vec[i]=t;
        }
        return vec[n];
    }
};