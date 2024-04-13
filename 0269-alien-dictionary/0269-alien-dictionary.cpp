class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<char>> vec(26);
        map<char, int> indegree;
        int n=words.size();
        for(int i=0;i<n;i++){
            string a = words[i];
            for(char c:a){
                indegree[c]=0;
            }
        }
        for(int i=0;i<n-1;i++){
            string a=words[i],b=words[i+1];
            int x=0,y=0;
            if(a.length() > b.length() && a.substr(0, b.length())==b){return "";}
            while(x<a.length() && y<b.length() && a[x]==b[y]){
                x++;y++;
            }
            if(x<a.length() && y<b.length()){
                vec[a[x]-'a'].push_back(b[y]);
                indegree[b[y]]++;
            }
        }
        queue<char> q;
        for(auto p:indegree){
            if(p.second == 0){
                q.push(p.first);
            }
        }
        string ans="";
        while(!q.empty()){
            char a = q.front();q.pop();
            ans+=a;
            for(auto c: vec[a-'a']){
                indegree[c]--;
                if(indegree[c] == 0){
                    q.push(c);
                }
            }
        }
        return ans.length() == indegree.size()?ans:"";
        
    }
};