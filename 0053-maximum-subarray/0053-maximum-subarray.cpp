class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),ans=nums[0],sum=nums[0];
        for(int i=1;i<n;i++){
            sum = max(nums[i], sum+nums[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};