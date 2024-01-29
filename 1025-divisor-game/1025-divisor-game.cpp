class Solution {
public:
    bool divisorGame(int n) {
        vector<int> vec(n+1,0);
        for(int i=2;i<=n;i++){
            for(int j=1;j*j<i;j++){
                if(i%j == 0 && vec[i-j] == 0){vec[i] = 1;break;}
            }
        }
        return vec[n];
    }
};