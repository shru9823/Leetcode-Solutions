class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](vector<int>&a, vector<int>& b){
            return a[0]<b[0];
        });
        int n=nums.size(), cnt=0, prev_end=nums[0][1];
        for(int i=1;i<n;i++){
            if(prev_end > nums[i][0]){
                cnt++;
                prev_end = min(prev_end, nums[i][1]);
            }else{
                prev_end = max(prev_end, nums[i][1]);
            }
        }
        return cnt;
    }
};