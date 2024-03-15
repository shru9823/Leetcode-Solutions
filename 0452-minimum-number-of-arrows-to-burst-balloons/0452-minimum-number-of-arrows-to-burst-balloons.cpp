class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>&a, const vector<int>&b){
            return a[0] < b[0];
        });
        int cnt=1, n=points.size(), prev_end = points[0][1];
        for(int i=1;i<n;i++){
            // cout<<points[i][0]<<endl;
            if(prev_end < points[i][0]){
                prev_end = points[i][1];
                cnt++;
            }else{
                prev_end = min(prev_end, points[i][1]);
            }
        }
        return cnt;
    }
};