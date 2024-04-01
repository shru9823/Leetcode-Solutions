class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mps, mpt;
        int n=s.length(), len = t.length(),cnt=0, l=0,r=n-1;
        if(n<len){return "";}
        vector<int> ans(3);
        for(int i=0;i<len;i++){
            mpt[t[i]]++;
        }
        cnt=mpt.size();
        for(int i=0;i<n;i++){
            mps[s[i]]++;
            if(mpt.find(s[i]) != mpt.end() && mpt[s[i]] == mps[s[i]]){
                cnt--;
            }
            if(cnt==0){r=i;break;}
        }
        if(cnt!=0){return "";}
        while(l<=r && (mpt[s[l]]<=mps[s[l]]-1)){
            mps[s[l]]--;
            l++;
        }
        ans[0]=r-l+1;
        ans[1] = l;
        ans[2] = r;
        r++;
        while(r<n){
            mps[s[r]]++;
            while(l<=r && (mpt[s[l]]<=mps[s[l]]-1)){
                mps[s[l]]--;
                l++;
            }
            if(r-l+1 < ans[0]){
                ans[0]=r-l+1;
                ans[1] = l;
                ans[2] = r;
            }
            r++;
        }
        return s.substr(ans[1], ans[0]);
    }
};