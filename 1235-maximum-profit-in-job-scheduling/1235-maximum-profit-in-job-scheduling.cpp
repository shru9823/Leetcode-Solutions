class Solution {
public:
    int find(vector<vector<int>>& vec, vector<int>& dp, int index){
        if(index == dp.size()){return 0;}
        if(dp[index]!=-1){return dp[index];}
        int l=index+1,r=dp.size()-1;
        bool found=0;
        while(l<=r){
            int mid = l+(r-l)/2;
            while(vec[mid][0] == vec[index][1]){found=true;l = mid--;}
            if(found==true){break;}
            if(vec[mid][0] > vec[index][1]){r=mid-1;}
            else{l = mid+1;}
        }
        return dp[index] = max(find(vec,dp,index+1), vec[index][2] + (l!=index?find(vec,dp,l):0));
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<int> dp(n,-1);
        vector<vector<int>> vec(n);
        for(int i=0;i<n;i++){vec[i] = {startTime[i],endTime[i],profit[i]};}
        sort(vec.begin(), vec.end());
        dp[0] = find(vec, dp, 0);
        return dp[0];
        
    }
};