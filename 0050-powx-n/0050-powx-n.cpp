class Solution {
public:
    int flag=0;
    double find(double x, long long n){
        if(n == 0){return 1;}
        double a = find(x, n/2);
        a =a*a;
        if(n%2 == 1){a *= x;}
        return a;
    }
    double myPow(double x, long long n) {
        if(n<0){n = n*(-1);flag=1;}
        cout<<n<<endl;
        double ans = find(x,n);
        if(flag==1){return 1/ans;}
        return ans;
    }
};