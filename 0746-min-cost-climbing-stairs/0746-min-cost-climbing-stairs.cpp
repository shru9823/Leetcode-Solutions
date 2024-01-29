class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a,b;
        a = cost[0];b=cost[1];
        int ans=0,aa=a,bb=b;
        for(int i=2;i<cost.size();i++){
            int c = min(aa,bb) + cost[i];
            // ans += c;
            aa = bb; bb = c;
        }
        return min(aa,bb);
    }
};