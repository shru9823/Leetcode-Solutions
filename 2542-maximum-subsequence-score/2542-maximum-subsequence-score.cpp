class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i] = make_pair(nums1[i], nums2[i]);
        }
        sort(vec.begin(), vec.end(), [](pair<int,int>a, pair<int,int>b){
            return a.second > b.second;
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum=0;
        for(int i=0;i<k;i++){
            sum += vec[i].first;
            pq.push(vec[i].first);
        }
        long long ans= sum*vec[k-1].second;
        for(int i=k;i<n;i++){
            sum += vec[i].first - pq.top(); pq.pop();
            pq.push(vec[i].first);
            ans = max(ans, sum*vec[i].second);
        }
        return ans;
    }
};