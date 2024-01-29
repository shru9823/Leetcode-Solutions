class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end=0,n=nums.size(),sofar=0;
        for(int i=0;i<=sofar;i++){
            sofar = max(sofar, i+nums[i]);
            if(sofar >= n-1){return true;}
        }
        return false;
    }
};