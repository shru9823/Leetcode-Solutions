class Solution {
public:
    int maxVowels(string s, int k) {
        int l=0, r=0, n=s.length(),ans=0, sum=0;
        while(r<n){
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u'){
                sum++;
            }
            if(r-l+1 > k){
                if(s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u'){
                    sum--;
                }
                l++;
            }
            r++;
            ans = max(ans, sum);
        }
        return ans;
    }
};