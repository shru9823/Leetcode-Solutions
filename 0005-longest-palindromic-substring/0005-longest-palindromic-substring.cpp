class Solution {
public:
    pair<int,int> find(int l, int r, string s){
        int n=s.length();
        while(l>=0 && r<n){
            if(s[l] == s[r]){
                l--;r++;
            }else{break;}
        }
        return make_pair(l+1, r-1);
    }
    string longestPalindrome(string s) {
        int n=s.length();
        pair<int,int> p;
        p = make_pair(0,0);
        for(int i=0;i<n;i++){
            auto a = find(i,i, s);
            if(p.second-p.first < a.second-a.first){
                p.first = a.first;
                p.second=a.second;
            }
            if(i+1==n){break;}
            a = find(i, i+1, s);
            if(p.second-p.first < a.second-a.first){
                p.first = a.first;
                p.second=a.second;
            }
        }
        return s.substr(p.first, p.second-p.first+1);
    }
};