class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        int root = -1;
        unordered_set<int> st;
        st.insert(l.begin(), l.end());
        st.insert(r.begin(), r.end());
        for(int i=0;i<n;i++){
            if(st.find(i) == st.end()){root = i;}
        }
        if(root == -1){return false;}
        stack<int> s;
        st.clear();
        st.insert(root);
        s.push(root);
        while(!s.empty()){
            int t = s.top();s.pop();
            if(l[t] != -1){
                if(st.find(l[t]) != st.end()){return false;}
                s.push(l[t]);
                st.insert(l[t]);
            }
            if(r[t] != -1){
                if(st.find(r[t]) != st.end()){return false;}
                s.push(r[t]);
                st.insert(r[t]);
            }
        }
        return st.size()==n;
    }
};