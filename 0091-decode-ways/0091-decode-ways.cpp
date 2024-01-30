class Solution {
public:
    int numDecodings(string s) {
        int one=1, two=1, n=s.length();
        if(s[0] == '0'){return 0;}
        for(int i=1; i<n;i++){
            int cur=0, num=stoi(s.substr(i-1, 2));
            if(s[i] == '0' && (num < 10 || num > 26)){
                return 0;
            }
            else if(s[i] != '0' && num <= 26 && num >= 10){
                cur += one+two;
            }
            else if(s[i] == '0'){
                cur += two;
            }
            else{
                cur += one;
            }
            two = one;
            one = cur;
        }
        return one;
    }
};