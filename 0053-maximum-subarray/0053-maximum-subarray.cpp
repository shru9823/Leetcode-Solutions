class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), sofar=0, ans=INT_MIN;
        for(int i=0;i<n;i++){
            sofar = max(sofar+nums[i], nums[i]);
            ans = max(ans, sofar);
        }
        return ans;
    }
};