class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minsofar=1,maxsofar=1,temp_max,ans=INT_MIN;
        for(auto a:nums){
            temp_max = max(a, max(a*maxsofar, a*minsofar));
            minsofar = min(a, min(a*maxsofar, a*minsofar));
            maxsofar = temp_max;
            ans = max(maxsofar, ans);
        }
        return ans;
    }
};