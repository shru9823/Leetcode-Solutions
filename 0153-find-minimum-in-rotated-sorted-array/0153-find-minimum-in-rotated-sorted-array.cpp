class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(),l=0,r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[(n+mid-1)%n] > nums[mid] && nums[(mid+1)%n] > nums[mid]){
                return nums[mid];
            }else if(nums[mid] > nums[r]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return nums[l];
    }
};