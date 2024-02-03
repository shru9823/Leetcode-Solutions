class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsofar=prices[0], ans=0, n=prices.size();
        for(int i=1;i<n;i++){
            ans = max(ans, prices[i]-minsofar);
            minsofar = min(minsofar, prices[i]);
        }
        return ans;
    }
};