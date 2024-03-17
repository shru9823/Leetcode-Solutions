class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod = 1;
        int n=nums.size(), zero=0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){zero++;}
            else{
                prod *= nums[i];
            }
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(zero > 0){
                if(nums[i] == 0 && zero-1 == 0){
                    ans[i]=prod;
                }
            }else{
                ans[i] = prod/nums[i];
            }
        }
        return ans;
    }
};