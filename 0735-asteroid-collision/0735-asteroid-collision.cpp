class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        st.push(asteroids[0]);
        for(int i=1;i<n;i++){
            // if(st.empty() || !st.empty() && ((asteroids[i] < 0 && st.top() < 0) || (asteroids[i] > 0 && st.top() > 0) || (asteroids[i] > 0 && st.top() < 0))){
            //     st.push(asteroids[i]);continue;
            // }
            int flag=1;
            while(!st.empty() && ( (asteroids[i] < 0 && st.top() > 0))){
                int a = abs(asteroids[i]);
                int b = abs(st.top());
                if(a == b){
                    st.pop();flag=0;break;
                }else if(a < b){
                    flag=0;break;
                }else{
                    flag=1;
                    st.pop();
                }
            }
            if(flag==1){
                st.push(asteroids[i]);
            }
        }
        vector<int> ans(st.size());
        int i=st.size()-1;
        while(!st.empty()){
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};