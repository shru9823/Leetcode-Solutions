class Solution {
public:
    int numTilings(int n) {
        int o=1,t=2,th=5,f=11;
        int MOD = pow(10,9)+7;
        if(n==1||n==2){return n;}
        else if(n==3){return 5;}
        else if(n==4){return 11;}
        for(int i=5;i<=n;i++){
            int temp = ((2*f)%MOD + t)%MOD;
            o = t; 
            t = th;
            th = f;
            f = temp;
        }
        return f;
    }
};