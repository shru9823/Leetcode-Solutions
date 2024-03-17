class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod = 1;
        int n=nums.size();
        vector<int> ans(n,1);
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1]*nums[i-1];
        }
        int prev = 1;
        for(int i=n-2;i>=0;i--){
            ans[i] = ans[i]*nums[i+1];
            // int temp = nums[i];
            nums[i] = nums[i+1]*nums[i]; 
            // prev = temp;
        }
        return ans;
    }
};