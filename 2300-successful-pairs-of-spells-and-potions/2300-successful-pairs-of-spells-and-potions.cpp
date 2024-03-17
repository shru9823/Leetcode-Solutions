class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n=spells.size(), m=potions.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int l=0,r=m-1;
            while(l<=r){
                int mid = l+(r-l)/2;
                if((long long)potions[mid]*spells[i] < success){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            ans.push_back(m-l);
        }
        return ans;
    }
};