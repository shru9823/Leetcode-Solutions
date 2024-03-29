class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(char r:s){
            if(r=='*'){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(r);
            }
        }
        string ans="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};