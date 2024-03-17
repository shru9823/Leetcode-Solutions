class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size()-1, n=nums.size();
        while(l<=r){
            int mid = l+(r-l)/2;
            cout<<l<<" "<<r<<endl;
            if(nums[mid] > (mid+1<n?nums[mid+1]:INT_MIN) && nums[mid] > (mid-1>=0?nums[mid-1]:INT_MIN)){
                return mid;      
            }else if(mid+1 < n && nums[mid] < nums[mid+1]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return l;
    }
};