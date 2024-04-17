class Solution {
public:
    int myAtoi(string s) {
        int num=0,sign=1,n=s.length(),i=0;
        while(i<n){
            if(s[i] == ' '){i++;}else{break;}
        }
        if(s[i] == '-'){sign=-1;i++;}
        else if(s[i] == '+'){sign=1;i++;}
        while(i<n && s[i]=='0'){
            i++;
        }
        while(i<n && s[i]>='0' && s[i] <= '9'){
            if(num>INT_MAX/10 || (num==INT_MAX/10 && s[i]-'0'>7)){return INT_MAX;}
            if(num<INT_MIN/10 || (num==INT_MIN/10 && s[i]-'0'>8)){return INT_MIN;}

            num = num*10 + (s[i]-'0')*sign;
            if(sign == -1 && num>0){num = num*sign;}
            i++;
        }
        return num;
    }
};