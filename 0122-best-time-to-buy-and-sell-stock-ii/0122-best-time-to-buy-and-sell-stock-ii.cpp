class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), sofar=prices[0], ans=0;
        for(int i=1;i<n;i++){
            if(sofar < prices[i]){
                ans += prices[i]-sofar;
                sofar = prices[i];
            }
            else{
                sofar = prices[i];
            }
        }
        return ans;
    }
};