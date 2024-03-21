class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        for(char a:s){
            // cout<<ans<<endl;
            if(a==' '){
                if(temp != ""){
                    ans = temp+ (ans=="" ? "":" ") + ans;
                }
                temp = "";
                
            }else{
                temp += a;
            }
        }
        if(temp!=""){ans = temp+(ans=="" ? "":" ") +ans;}
        return ans;
    }
};