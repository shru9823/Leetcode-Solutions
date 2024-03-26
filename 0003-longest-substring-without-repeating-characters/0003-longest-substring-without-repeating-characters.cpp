class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(), l=0, r=0,ans=0;
        vector<int> mp(128, 0);
        while(r<n){
            while(mp[s[r]] > 0){
                mp[s[l]]--;
                l++;
            }
            mp[s[r]]++;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};