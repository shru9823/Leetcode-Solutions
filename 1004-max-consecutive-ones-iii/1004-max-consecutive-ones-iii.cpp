class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0, l=0,r=0, cnt=0;
        while(r<nums.size()){
            if(nums[r] == 0){
                cnt++;
                while(cnt>k){
                    cnt = cnt - (nums[l++] == 0?1:0);
                }
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};