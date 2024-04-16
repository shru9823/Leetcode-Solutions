class Solution {
public:
    int hIndex(vector<int>& cit) {
        vector<int> vec(1001, 0);
        int ans=0,cur=0;
        for(auto a:cit){
            vec[a]++;
        }
        for(int i=1000;i>=1;i--){
            cur += vec[i];
            if(cur >= i){
                ans = max(ans, i);
            }
        }
        return ans;
    }
};