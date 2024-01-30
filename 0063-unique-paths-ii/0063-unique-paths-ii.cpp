class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int m=nums.size(),n=nums[0].size();
        if(nums[0][0] == 1){return 0;}
        else{nums[0][0] = 1;}
        for(int i=1;i<n;i++){
            if(nums[0][i] == 1 || nums[0][i-1]==0){nums[0][i] = 0;}
            else{
                nums[0][i] = 1;
            }
        }
        for(int i=1; i<m;i++){
            for(int j=0;j<n;j++){
                if(nums[i][j] == 1){nums[i][j] = 0;}
                else{
                    nums[i][j] = (j==0?0:nums[i][j-1]) + nums[i-1][j];
                }
            }
        }
        return nums[m-1][n-1];
    }
};