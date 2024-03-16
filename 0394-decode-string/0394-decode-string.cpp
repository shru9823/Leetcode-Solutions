class Solution {
public:
    string decodeString(string s) {
        stack<int> op;
        stack<string> st;
        int n=s.length();
        string cur="";
        int prev=0;
        for(int i=0;i<n;i++){
            if(s[i]-'0' >= 0 && s[i]-'0' <= 9){
                prev = prev*10 + (s[i]-'0');
            }else if(s[i] == '['){
                op.push(prev);
                st.push(cur);
                cur= "";
                prev=0;
            }else if(s[i] == ']'){
                string t = st.top();
                st.pop();
                for(int i=op.top();i>0;i--){
                    t = t + cur;
                }
                op.pop();
                cur = t;
            }else{
                cur = cur+s[i];
            }
        }
        return cur;
    }
    
};