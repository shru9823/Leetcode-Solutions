class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size(), l=newInterval[0], r=newInterval[1], i=0;
        vector<vector<int>> ans;
        if(n == 0){return {{l,r}};}
        while(i<n && intervals[i][1] < l){
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        while(i<n && intervals[i][0] <= r){
            l = min(l, intervals[i][0]);
            r = max(r, intervals[i][1]);
            i++;
        }
        ans.push_back({l,r});
        while(i<n){
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        return ans;
    }
};