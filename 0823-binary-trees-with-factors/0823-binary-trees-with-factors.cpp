class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& nums) {
        int n = nums.size(),MOD = pow(10,9)+7;
        long ans=0;
        vector<long> vec(n, 1);
        sort(nums.begin(), nums.end());
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 && mp.find(nums[i]/nums[j]) != mp.end()){
                    vec[i] = vec[i] + (long)(vec[mp[nums[j]]] * vec[mp[nums[i]/nums[j]]])%MOD;
                }
            }
            ans = (long)(ans+vec[i])%MOD;
        }
        return ans;
    }
};