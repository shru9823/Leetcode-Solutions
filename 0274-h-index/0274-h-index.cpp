class Solution {
public:
    int hIndex(vector<int>& cit) {
        int ans=0,cur=0;
        auto maxi = std::max_element(cit.begin(), cit.end());
        vector<int> vec(*maxi +1, 0);
        for(auto a:cit){
            vec[a]++;
        }
        for(int i=*maxi;i>=1;i--){
            cur += vec[i];
            if(cur >= i){
                ans = max(ans, i);
            }
        }
        return ans;
    }
};