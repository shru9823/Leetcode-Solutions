class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec(n,INT_MAX);
        vec[0]=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j >= n){break;}
                vec[i+j] = min(vec[i+j],1+vec[i]);
            }
        }
        return vec[n-1];
    }
};