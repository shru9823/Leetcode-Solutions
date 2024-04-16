class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> vec(26,0);
        int l=0,r=0,n=s.length(),max_cnt=0,ans=0;
        while(r<n){
            vec[s[r]-'A']++;
            int cur_cnt = vec[s[r]-'A'];
            max_cnt = max(cur_cnt, max_cnt);
            if(r-l+1-max_cnt > k){
                vec[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};