class Codec {
public:
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        if(strs.size()==0){return "";}
        string str="";
        for(auto s: strs){
            for(auto a:s){
                if(a=='/'){
                    str += "//";
                }else{
                    str += a;
                }
            }
            str += "/:";
        }
        return str;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        string cur="";
        int i=0,n=s.length();
        for(int i=0;i<n;i++){
            if(i<n-1 && s[i]=='/' && s[i+1]=='/'){
                cur += '/';
                i++;
            }else if(i<n-1 && s[i]=='/' && s[i+1]==':'){
                ans.push_back(cur);
                cur="";
                i++;
            }else{
                cur+=s[i];
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));