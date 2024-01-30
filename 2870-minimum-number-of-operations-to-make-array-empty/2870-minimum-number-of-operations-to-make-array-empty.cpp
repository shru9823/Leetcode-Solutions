class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto a:mp){
            if(a.second==1){
                return -1;
            }
            else{
                ans += a.second/3;
                if(a.second%3!=0){
                    ans++;
                }
            }
        }
        return ans;
    }
};