class Solution {
public:
    int compress(vector<char>& chars) {
        int res=0, i=0;
        while(i < chars.size()){
            int cnt=1;
            while(i+1<chars.size() && chars[i] == chars[i+1]){
                i++;
                cnt++;
            }
            chars[res++]=chars[i];
            if(cnt > 1){
                for(char c : to_string(cnt)){
                    chars[res++] = c;
                }
            }
            i++;
        }
        return res;
    }
};