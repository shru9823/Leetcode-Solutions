class Solution {
public:
    int minPathSum(vector<vector<int>>& nums) {
        int m=nums.size(), n=nums[0].size();
        for(int j=1;j<n;j++){
            nums[0][j] += nums[0][j-1];
        }
        for(int i=1;i<m;i++){
            nums[i][0] += nums[i-1][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                nums[i][j] += min(nums[i-1][j],nums[i][j-1]);
            }
        }
        return nums[m-1][n-1];
    }
};