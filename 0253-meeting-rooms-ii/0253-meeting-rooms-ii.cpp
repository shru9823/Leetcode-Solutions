class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans=1,i=0,n=intervals.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[i][1]);i++;
        while(i<n){
            int start=intervals[i][0],end=intervals[i][1];
            while(pq.size() && start >= pq.top()){
                pq.pop();
            }
            pq.push(end);
            i++;
            ans = max(ans,int(pq.size()));
        }
        return ans;
    }
};