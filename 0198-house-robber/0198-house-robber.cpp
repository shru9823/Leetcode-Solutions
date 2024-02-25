class Solution {
public:
    int rob(vector<int>& nums) {
        int one=nums[0],two=0, ans=nums[0], cur=nums[0], n=nums.size();
        for(int i=1;i<n;i++){
            cur = max(nums[i]+two, cur-nums[i-1]+nums[i]);
            ans = max(ans, cur);
            two = one; one=cur;
        }
        return ans;

    }
};