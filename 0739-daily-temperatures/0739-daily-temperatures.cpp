class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        int n=temp.size();
        vector<int> ans(n,0);
        st.push(make_pair(temp[n-1],n-1));
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first <= temp[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top().second - i;
            }
            st.push(make_pair(temp[i], i));
        }
        return ans;
    }
};