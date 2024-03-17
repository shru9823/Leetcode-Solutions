class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(c!=0){
            int ab, bb, cb;
            ab = a%2;
            bb = b%2;
            cb = c%2;
            // cout<<(ab||bb)<<endl;
            if((ab||bb) != cb){
                ans++;
                if(ab == bb && cb == 0){
                    ans++;
                }
            }
            c = c>>1;
            b = b>>1;
            a = a>>1;
        }
        while(b != 0){
            int bb = b%2;
            if(bb == 1){ans++;}
            b = b>>1;
        }
        while(a != 0){
            int ab = a%2;
            if(ab == 1){ans++;}
            a = a>>1;
        }
        return ans;
    }
};