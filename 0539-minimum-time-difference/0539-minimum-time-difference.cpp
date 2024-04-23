class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int> vec;
        for(int i=0;i<n;i++){
            string a = timePoints[i].substr(0,2);
            string b = timePoints[i].substr(3,2);
            int hr = stoi(a);
            int mi = stoi(b);
            vec.push_back(hr*60 + mi);
        }
        sort(vec.begin(), vec.end());
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            ans = min(ans, vec[i]-vec[i-1]);
        }
        ans = min(ans, 1440-vec[n-1]+vec[0]);
        return ans;
    }
};