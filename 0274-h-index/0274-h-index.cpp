class Solution {
public:
    int hIndex(vector<int>& cit) {
        int ans=0,cur=0, n=cit.size();
        vector<int> vec(n +1, 0);
        for(auto a:cit){
            vec[min(a,n)]++;
        }
        for(int i=n;i>=1;i--){
            cur += vec[i];
            if(cur >= i){
                ans = max(ans, i);
            }
        }
        return ans;
    }
};