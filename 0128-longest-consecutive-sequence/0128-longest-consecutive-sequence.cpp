class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(auto a:nums){
            st.insert(a);
        }
        int ans=0;
        for(auto a:st){
            if(st.find(a+1) == st.end()){
                int cnt=1;
                while(st.find(a-1) != st.end()){
                    a--;
                    cnt++;
                }
                ans=max(ans, cnt);
            }
        }
        return ans;
    }
};