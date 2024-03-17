class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size(), l=1, r=*max_element(piles.begin(), piles.end());
        while(l<=r){
            int mid = l+(r-l)/2;
            long long hr=0;
            for(int i=0;i<n;i++){
                hr += piles[i]<mid?1:(piles[i]%mid != 0)?(piles[i]/mid) + 1: piles[i]/mid;
            }
            if(hr <= h){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};