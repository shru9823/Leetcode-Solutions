class Solution {
public:
    int numDecodings(string s) {
        
        int n=s.length(), one=1,two=1,cur=1;
        if(s[0] == '0'){return 0;}
        char prev = s[0];
        for(int i=1;i<n;i++){
            cur=0;
            string a = "";
            a += s[i-1];
            a+=s[i];
            if(s[i] == '0' && prev > '2'){return 0;}
            cout<<a<<endl;
            if(a <= "26" && a >= "10"){
                cur = two;
            }
            if(s[i] != '0'){
                cur += one;
            }
            prev= s[i]
;           two = one;
            one =cur;
        }
        return cur;
    }
};