class Solution {
public:
    int find(vector<int>&dp, int ele){
        int l=0,r=dp.size()-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(dp[mid]==ele){return mid;}
            else if(dp[mid] < ele){l=mid+1;}
            else{r=mid;}
        }
        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i] > dp[dp.size()-1]){dp.push_back(nums[i]);}
            else{dp[find(dp, nums[i])]=nums[i];}
        }
        return dp.size();
    }
};