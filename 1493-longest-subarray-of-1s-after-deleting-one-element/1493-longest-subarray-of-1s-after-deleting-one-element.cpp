class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0, cnt=0, ans=0;
        while(r<nums.size()){
            if(nums[r] == 0){
                cnt++;
                while(cnt > 1){
                    cnt = cnt-(nums[l++]==0?1:0);
                }
            }
            ans = max(ans, r-l);
            r++;
        }
        return ans;
    }
};